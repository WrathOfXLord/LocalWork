#ifndef _MEMORY_POOL_HPP_
#define _MEMORY_POOL_HPP_
#include <iostream>
#include <vector>
#include <mutex>

class MemoryPool {
private:
    using byte = char;
    using byte_ptr = byte *;
    struct BlockHeader {
        BlockHeader *next;
    };
    const std::vector<std::size_t> m_blockSizes; // Her blok için boyutu
    std::vector<byte_ptr> m_blockPtrs;           // Depolama alanı blokları
    std::vector<std::size_t> m_blockCounts;      // Her blok için blok sayısı
    std::vector<std::size_t> m_blockFreeCounts;  // Her blok için kullanılmayan blok sayısı
    std::vector<std::mutex> m_blockMutexes;      // Her blok için kilit mekanizması
    std::mutex m_globalMutex;                    // Global kilit mekanizması
    byte_ptr m_startPtr;                            // Depolama alanının başlangıç adresi
    byte_ptr m_endPtr;                              // Depolama alanının son adresi
public:
    MemoryPool(const MemoryPool &) = delete;
    MemoryPool &operator=(const MemoryPool &) = delete;
    MemoryPool(const std::vector<std::size_t> &blockSizes, std::size_t blockSizeCounts) : m_blockSizes(blockSizes), m_startPtr(nullptr), m_endPtr(nullptr) {
        // Her blok boyutu için blok sayısını hesapla
        m_blockCounts.resize(blockSizes.size());
        for (std::size_t i = 0; i < blockSizes.size(); ++i) {
            m_blockCounts[i] = blockSizeCounts;
        }
        // Depolama alanı için yeterli büyüklükte bellek ayrıla
        std::size_t totalSize = 0;
        for (std::size_t i = 0; i < blockSizes.size(); ++i) {
            totalSize += blockSizes[i] * blockSizeCounts;
        }
        m_startPtr = new byte[totalSize];
        m_endPtr = m_startPtr + totalSize;
        // Her blok için depolama alanı oluştur ve blok başlıklarını bağla
        m_blockPtrs.resize(blockSizes.size());
        m_blockFreeCounts.resize(blockSizes.size());
        m_blockMutexes.resize(blockSizes.size());
        byte_ptr currentPtr = m_startPtr;
        for (std::size_t i = 0; i < blockSizes.size(); ++i) {
            m_blockPtrs[i] = currentPtr;
            m_blockFreeCounts[i] = blockSizeCounts;
            BlockHeader *header = reinterpret_cast<BlockHeader *>(currentPtr);
            for (std::size_t j = 0; j < blockSizeCounts - 1; ++j) {
                BlockHeader *nextHeader = reinterpret_cast<BlockHeader *>(currentPtr + blockSizes[i]);
                header->next = nextHeader;
                header = nextHeader;
                currentPtr += blockSizes[i];
            }
            header->next = nullptr;
            currentPtr += blockSizes[i];
        }
    }
    ~MemoryPool() {
        delete[] m_startPtr;
    }
    void *allocate(std::size_t size) {
        // En uygun blok boyutunu bul
        std::size_t blockIndex = 0;
        for (std::size_t i = 0; i < m_blockSizes.size(); ++i) {
            if (m_blockSizes[i] >= size) {
                blockIndex = i;
                break;
            }
        }
        // Kilitleri alarak boş bir blok bul
        m_blockMutexes[blockIndex].lock();
        BlockHeader *header = reinterpret_cast<BlockHeader *>(m_blockPtrs[blockIndex]);
        if (!header) {
            m_blockMutexes[blockIndex].unlock();
            return nullptr;
        }
        m_blockPtrs[blockIndex] = header->next;
        --m_blockFreeCounts[blockIndex];
        m_blockMutexes[blockIndex].unlock();
        return header;
    }
    void deallocate(void *ptr) {
        // Bloğun boyutunu belirle
        byte_ptr blockPtr = static_cast<byte_ptr>(ptr);
        std::size_t blockIndex = 0;
        for (std::size_t i = 0; i < m_blockSizes.size(); ++i) {
            if (blockPtr >= m_blockPtrs[i] && blockPtr < m_blockPtrs[i] + m_blockSizes[i] * m_blockCounts[i]) {
                blockIndex = i;
                break;
            }
        }
        // Kilitleri alarak bloğu geri ekle
        m_blockMutexes[blockIndex].lock();
        BlockHeader *header = reinterpret_cast<BlockHeader *>(ptr);
        header->next = reinterpret_cast<BlockHeader *>(m_blockPtrs[blockIndex]);
        m_blockPtrs[blockIndex] = static_cast<byte_ptr>(ptr);
        ++m_blockFreeCounts[blockIndex];
        m_blockMutexes[blockIndex].unlock();
    }
};

#endif