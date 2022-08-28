#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <vector>
#include <thread>
#include <chrono>

#include "VulkanRenderer.hpp"

using namespace std::chrono_literals;


class AllocationStats
{
    friend std::ostream &operator<<(std::ostream &out, const AllocationStats &rhs)
    {
        out << "\nCurrent Memory Usage: " << rhs.currentUsage() << " bytes. \n";
        out << "Total Allocated: " << rhs.allocated << " bytes, Total Released: " << rhs.released << " bytes.\n";
        return out;
    }

public:
    size_t allocated, released;
    size_t currentUsage() const { return allocated - released; }
};

static AllocationStats memStats{};

void *operator new(std::size_t size)
{
    std::cout << "Allocated " << size << " bytes of memory.\n";
    memStats.allocated += size;
    return std::malloc(size);
}

void operator delete(void *memory, std::size_t size)
{
    std::cout << "Released " << size << " bytes of memory.\n";
    memStats.released += size;
    std::free(memory);
}

void operator delete[](void *memory, std::size_t size)
{
    // std::cout << "Released " << size << " bytes of memory.\n";
    memStats.released += size;
    std::free(memory);
}


int main()
{
    {
        VulkanRenderer vlknRenderer;

        if (vlknRenderer.init(500, 500, "Vulkan App") != 0)
            return EXIT_FAILURE;


        // memory usage status
        bool isClosed{};
        std::thread t1{[&isClosed]() {
            do {
                std::cout << memStats << "\n";
                std::this_thread::sleep_for(1000ms);
            } while (!isClosed);
        }};

        try
        {
            vlknRenderer.run();
            isClosed = true;
        }
        catch (const std::exception &ex)
        {
            std::cerr << ex.what() << "\n";
            return EXIT_FAILURE;
        }

        // destroys vulkan instance
        vlknRenderer.cleanUp();
        // //  closes all glfw components
        // VulkanRenderer::terminateAll();

        t1.join();
    }
    std::this_thread::sleep_for(1s);
    std::cout << memStats << "\n";
    return EXIT_SUCCESS;
}