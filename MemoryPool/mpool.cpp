#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

template <typename T>
class MemoryPool {
public:
    MemoryPool() : MemoryPool(64) {}

    MemoryPool(size_t blockSize) : m_blockSize(blockSize) {
        allocateBlock();
    }

    ~MemoryPool() {
        for (auto block : m_blocks) {
            delete[] block;
        }
    }

    T* allocate() {
        if (m_freeList == nullptr) {
            allocateBlock();
        }

        T* block = reinterpret_cast<T*>(m_freeList);
        m_freeList = *reinterpret_cast<T**>(m_freeList);
        m_numAllocated.fetch_add(1, std::memory_order_relaxed);
        return block;
    }

    void deallocate(T* block) {
        *reinterpret_cast<T**>(block) = m_freeList;
        m_freeList = block;
        m_numAllocated.fetch_sub(1, std::memory_order_relaxed);
    }

    size_t getNumAllocated() const {
        return m_numAllocated.load(std::memory_order_relaxed);
    }

private:
    void allocateBlock() {
        size_t blockSize = m_blockSize * sizeof(T);
        char* block = new char[blockSize];

        for (size_t i = 0; i < m_blockSize - 1; i++) {
            T* currentBlock = reinterpret_cast<T*>(block + i * sizeof(T));
            T* nextBlock = reinterpret_cast<T*>(block + (i + 1) * sizeof(T));
            *currentBlock = *nextBlock;
        }

        *reinterpret_cast<T**>(block + (m_blockSize - 1) * sizeof(T)) = m_freeList;
        m_freeList = reinterpret_cast<T*>(block);
        m_blocks.push_back(block);
    }

    char* m_freeList = nullptr;
    size_t m_blockSize = 0;
    std::vector<char*> m_blocks;
    std::atomic<size_t> m_numAllocated = { 0 };
};

int main() {
    MemoryPool<int> pool(1024);

    std::vector<std::thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.emplace_back([&pool]() {
            for (int j = 0; j < 100000; j++) {
                int* a = pool.allocate();
                *a = j;
                pool.deallocate(a);
            }
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Number of allocated blocks: " << pool.getNumAllocated() << std::endl;

    return 0;
}
