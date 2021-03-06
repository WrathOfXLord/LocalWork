#ifndef _VULKAN_RENDERER_HPP_
#define _VULKAN_RENDERER_HPP_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
// std library
#include <set>

#include "Window.hpp"
#include "Utilities.hpp"

class VulkanRenderer
{
private:
    Window window;
    // Vulkan Components
    VkInstance instance;

    struct {
        VkPhysicalDevice physicalDevice;
        VkDevice logicalDevice;
    } mainDevice;

    VkQueue graphicsQueue;
    VkQueue presentationQueue;

    VkSurfaceKHR surface;

// Vulkan helper functions
    // create Functions
    void createInstance();          //1st call from init
    void createLogicalDevice();     //4th call from init
    void createSurface();           //2nd call from init

// support functions
    // checker functions
    
    bool checkInstanceExtensionSupport(std::vector<const char *> *checkExtensions);     //invoked by createInstance
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);      //invoked by checkDeviceSuitable
    bool checkDeviceSuitable(VkPhysicalDevice device);              //invoked by getPhysicalDevice

    // getter functions

    void getPhysicalDevice();       //3rd call from init
    QueueFamilyIndices getQueueFamillies(VkPhysicalDevice device);  //invoked by checkDeviceSuitable
    SwapChainDetails getSwapChainDetails(VkPhysicalDevice device);  //invoked by checkDeviceSuitable

    
public:
    // VulkanRenderer();
    // ~VulkanRenderer();

    void static terminateAll() { glfwTerminate(); }
    void cleanUp();
    int init(const int w, const int h, const std::string_view &title);
    void run();

};

#endif