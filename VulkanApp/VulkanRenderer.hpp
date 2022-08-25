#ifndef _VULKAN_RENDERER_HPP_
#define _VULKAN_RENDERER_HPP_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
// std library
#include <set>
// #include <algorithm>

#include "Window.hpp"
#include "Utilities.hpp"

class VulkanRenderer
{
private:
    Window window;
    // Vulkan Components
    VkInstance instance;

    struct {
        VkPhysicalDevice physicalDevice {};
        VkDevice logicalDevice {};
    } mainDevice;

    VkQueue graphicsQueue;
    VkQueue presentationQueue;

    VkSurfaceKHR surface;

// Vulkan helper functions
    // create Functions
    void createInstance();          //1st call from init
    void createSurface();           //2nd call from init
    void createLogicalDevice();     //4th call from init
    void createSwapChain();

// --support functions
    // --checker functions
    
    bool checkInstanceExtensionSupport(const std::vector<const char *> &checkExtensions);     //invoked by createInstance
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);      //invoked by isPhysicalDeviceSuitable
    bool isPhysicalDeviceSuitable(VkPhysicalDevice device);         //invoked by getPhysicalDevice
    int ratePhysicalDeviceSuitability(VkPhysicalDevice device);     //invoked by getPhysicalDevice
    
    // --getter functions
    void getPhysicalDevice();       //3rd call from init
    QueueFamilyIndices getQueueFamillies(VkPhysicalDevice device);  //invoked by isPhysicalDeviceSuitable
    SwapChainDetails getSwapChainDetails(VkPhysicalDevice device);  //invoked by isPhysicalDeviceSuitable

    // --selector Functions
    VkSurfaceFormatKHR selectBestSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &formats);
    VkPresentModeKHR selectBestPresentationMode(const std::vector<VkPresentModeKHR> &presentationModes);
    VkExtent2D selectSwapExtent(const VkSurfaceCapabilitiesKHR &surfaceCapabilities);
public:
    // VulkanRenderer();
    // ~VulkanRenderer();

    void static terminateAll() { glfwTerminate(); }
    void cleanUp();
    int init(const int w, const int h, const std::string_view &title);
    void run();

};

#endif