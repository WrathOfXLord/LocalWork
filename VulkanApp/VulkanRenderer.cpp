#include "VulkanRenderer.hpp"
#include <iostream>
#include <cstring>
#include <limits>
#include <algorithm>

// Initializes window and vulkan components
int VulkanRenderer::init(const int w, const int h, const std::string_view &title)
{
    if (window.init(w, h, title) == EXIT_FAILURE)
        return EXIT_FAILURE;
    try
    {
        createInstance();
        createSurface();
        getPhysicalDevice();
        createLogicalDevice();
        createSwapchain();
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << err.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// if there is any creation then it also needs to be destroyed afterwards
void VulkanRenderer::cleanUp()
{
    vkDestroySwapchainKHR(mainDevice.logicalDevice, swapchain, nullptr);
    vkDestroyDevice(mainDevice.logicalDevice, nullptr);
    vkDestroySurfaceKHR(instance, surface, nullptr);
    vkDestroyInstance(instance, nullptr);
}

// Checks required extensions for Vulkan instance then assign it to VulkanRenderer object's instance pointer
void VulkanRenderer::createInstance()
{
    // info about application itself
    // most data here doesn't affect the program and is for developer convenience
    VkApplicationInfo appInfo{};
    // sType = structure type
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    // Custom Name of the app
    appInfo.pApplicationName = "Vulkan App";
    // custom version of the app
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    // custom engine name
    appInfo.pEngineName = "No Engine";
    // custom engine version
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    // Vulkan version
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // creation information for a vkinstance
    VkInstanceCreateInfo createInfo{};
    // sType = structure type
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    // pointer to application info struct
    createInfo.pApplicationInfo = &appInfo;

    // Create list to hold instance extensions
    std::vector<const char *> instanceExtensions{};
    // Set up extensions instance will use. GLFW may require multiple extensions
    uint32_t glfwExtensionCount{0};
    // Extensions passed as array of c-strings, so need pointer (the array) to pointer (c-strings)
    const char **glfwExtensions;

    // Get GLFW Extensions and Count
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    // Add GLFW Extensions to list of extensions
    for (size_t e{}; e < glfwExtensionCount; ++e)
    {
        instanceExtensions.push_back(glfwExtensions[e]);
    }

    // Check instance extensions supported
    if (!checkInstanceExtensionSupport(instanceExtensions))
        throw std::runtime_error{"VkInstance does not support required extensions"};

    createInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtensions.size());
    // returns pointer to extension names (to pointers)
    createInfo.ppEnabledExtensionNames = instanceExtensions.data();

    // TODO: Set up validation layers that instance will use
    // enabled validation count, by default there is no validation
    createInfo.enabledLayerCount = 0;
    // no validation so nullptr
    createInfo.ppEnabledLayerNames = nullptr;

    // create instance
    VkResult result{vkCreateInstance(&createInfo, nullptr, &instance)};
    if (result != VK_SUCCESS)
    {
        throw std::runtime_error{"Failed to Create a Vulkan Instance"};
    }
}

// Check if GLFW extensions are supported by Vulkan instance or not
bool VulkanRenderer::checkInstanceExtensionSupport(const std::vector<const char *> &checkExtensions)
{
    // need to get number of extensions to create array of correct size to hold extensions
    uint32_t extensionCount{0};
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    // create a list of VKExtensionProperties using count
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    // Check if given extensions are in list of available extensions
    for (const auto &checkExt : checkExtensions)
    {
        bool hasExtension{false};
        for (const auto &ext : extensions)
        {
            // std::cout << "Extension: " << ext.extensionName << "\n";
            if (std::strcmp(checkExt, ext.extensionName) == 0)
            {
                hasExtension = true;
                break;
            }
        }

        if (!hasExtension)
        {
            return false;
        }
    }

    return true;
}

// Check physical device's extensions are supported or not
bool VulkanRenderer::checkDeviceExtensionSupport(VkPhysicalDevice device)
{

    // Get device extension count
    uint32_t extensionCount{0};
    vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

    // if there is no extension, return failure
    if (extensionCount == 0)
        return false;

    // Populate list of extensions
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, extensions.data());

    for (const auto &deviceExtension : deviceExtensions)
    {
        bool hasExtension{false};
        for (const auto &extension : extensions)
        {
            if (std::strcmp(extension.extensionName, deviceExtension) == 0)
            {
                hasExtension = true;
                break;
            }
        }

        if (!hasExtension)
            return false;
    }

    return true;
}

// Keep Windows visible until it is closed
void VulkanRenderer::run()
{
    this->window();
}

// Selects the most suitable physical device (gpu) and assign it to VulkanRenderer object's physical device pointer.
void VulkanRenderer::getPhysicalDevice()
{
    // Enumerate physical devices the vkInstance can access
    uint32_t deviceCount{0};
    // get count of physical devices
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

    // if there is no devices, then none support Vulkan.
    if (deviceCount == 0)
        throw std::runtime_error{"Cannot find GPU that supports Vulkan Instance"};

    // get list of physical devices
    std::vector<VkPhysicalDevice> deviceList(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, deviceList.data());

    {
        int highestScore{};
        for (const auto &device : deviceList)
        {
            // to use the most suitable device evaluates device suitability
            int deviceScore{ratePhysicalDeviceSuitability(device)};
            if (isPhysicalDeviceSuitable(device) && deviceScore > highestScore)
            {
                mainDevice.physicalDevice = device;
                std::cout << "score : " << deviceScore << "\n";
                highestScore = deviceScore;
            }
        }
    }

    // If no physical device is assigned, then no suitable device.
    if (mainDevice.physicalDevice == VK_NULL_HANDLE)
        throw std::runtime_error{"Failed to find a suitable physical device"};
}

// Check the given device is suitable for Vulkan instance or not
// First, check if there are any graphics queue and presentation queue (can be the same queue), then check device's extension support and lastly, check Swap Chain support
bool VulkanRenderer::isPhysicalDeviceSuitable(VkPhysicalDevice device)
{
    QueueFamilyIndices indices{getQueueFamillies(device)};

    // after getting queue famillies check if given extensions are supported or not
    bool extensionSupported{checkDeviceExtensionSupport(device)};

    // to check swapchain is valid or not
    bool swapChainValid{false};

    // if extensions are not supported then, no need to check Swap Chain is supported or not
    if (extensionSupported)
    {
        // get details about Swap Chain
        SwapChainDetails swapChainDetails{getSwapChainDetails(device)};
        // if there is no format or presentation mode for Swap Chain then return false
        swapChainValid = !(swapChainDetails.surfaceFormats.empty() || swapChainDetails.presentationModes.empty());
    }

    return indices.isValid() && extensionSupported && swapChainValid;
}

// Rates the given device according to its capabilities and returns a score for the device
int VulkanRenderer::ratePhysicalDeviceSuitability(VkPhysicalDevice device)
{

    // Information about the device itself (Id, name, type, vendor, etc.)
    VkPhysicalDeviceProperties deviceProperties;
    vkGetPhysicalDeviceProperties(device, &deviceProperties);

    // Information about what the device can do (geo shader, tessalation shader, wide lines, etc.)
    VkPhysicalDeviceFeatures deviceFeatures;
    vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

    std::cout << "device info: " << deviceProperties.deviceID << " - " << deviceProperties.deviceName << "\n";

    // Application can't function without geometry shaders
    if (!deviceFeatures.geometryShader)
    {
        return 0;
    }

    int deviceScore{};

    // Maximum possible size of textures affects graphics quality
    deviceScore += deviceProperties.limits.maxImageDimension2D;

    // Discrete GPUs have a significant performance advantage
    if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
    {
        deviceScore += 1000;
    }

    return deviceScore;
}

// Check if the given device has any graphics queue and presentation queue, if there are no graphics queue and presentation queue then the device is not valid.
// Queue types; graphics, transfer, and computation. Graphics queue and presentation queue can be the same.
QueueFamilyIndices VulkanRenderer::getQueueFamillies(VkPhysicalDevice device)
{

    QueueFamilyIndices indices;

    // Get all queue family property info for the given device
    uint32_t queueFamilyCount{0};
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilyList(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilyList.data());

    // Go through each queue family and check if it has at least one of the required types of queue
    int index{0};
    for (const auto &queueFamily : queueFamilyList)
    {
        // First check if queue family at least 1 graphics queue in that family (could have no queues)
        // Queue can be multiple types defined through bitfield. Need to bitwise AND with VK_QUEUE_*_BIT to check if has required type
        if (queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
        {
            // if queue family is valid, then get index
            indices.graphicsFamily = index;
        }

        // Check if Queue Family Supports Presentation (By Checking any presentation queue is exist or not)
        VkBool32 presentationSupport{false};
        vkGetPhysicalDeviceSurfaceSupportKHR(device, index, surface, &presentationSupport);
        if (queueFamily.queueCount > 0 && presentationSupport)
        {
            // Check if queue is presentation type (can be both graphics and presentation)
            indices.presentationFamily = index;
        }

        // check if queue family indices are in a valid state, stop searching
        if (indices.isValid())
        {
            break;
        }

        ++index;
    }
    return indices;
}

// Creates a logical device and assigns it to VulkanRenderer object's logical device pointer after acquiring physical device info
void VulkanRenderer::createLogicalDevice()
{
    // Get the queue family indices for the chosen physical device
    QueueFamilyIndices indices{getQueueFamillies(mainDevice.physicalDevice)};

    // if values are the same then, one of them will be discarded (only unique values are allowed)
    std::set<int> queueFamilyIndices{indices.graphicsFamily, indices.presentationFamily};
    // vector for queue creation information and set for family indices
    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos(queueFamilyIndices.size());

    {
        size_t setIndex{};
        // Queue the logical device needs to create and info to do so
        for (int queueFamilyIndex : queueFamilyIndices)
        {
            VkDeviceQueueCreateInfo queueCreateInfo{};
            queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
            // the index of the family to create a queue create from
            queueCreateInfo.queueFamilyIndex = queueFamilyIndex;
            // number of the queues to create
            queueCreateInfo.queueCount = 1;
            float priority{1.0};
            // Vulkan needs to know how to handle multiple queues so decide priority (1 - highest, 0 - lowest)
            queueCreateInfo.pQueuePriorities = &priority;
            queueCreateInfos[setIndex++] = queueCreateInfo;
        }
    }

    // // debug line
    // std::cout << "size of qinfos size: " << queueCreateInfos.size() << "\n";

    // information to create logical device (sometimes called "device")
    VkDeviceCreateInfo deviceCreationInfo{};
    deviceCreationInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    // number of queue create infos
    deviceCreationInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
    // list of queue create infos so device can create required queues
    deviceCreationInfo.pQueueCreateInfos = queueCreateInfos.data();
    // number of enabled logical device extensions
    deviceCreationInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
    // list of enabled logical device extensions
    deviceCreationInfo.ppEnabledExtensionNames = deviceExtensions.data();

    // Physical device features the logical device will be using
    VkPhysicalDeviceFeatures deviceFeatures{};

    // physical device features that logical device will use
    deviceCreationInfo.pEnabledFeatures = &deviceFeatures;

    // Create the logical device for the given physical device
    VkResult result{vkCreateDevice(mainDevice.physicalDevice, &deviceCreationInfo, nullptr, &mainDevice.logicalDevice)};
    if (result != VK_SUCCESS)
    {
        throw std::runtime_error{"Failed to Create a Logical Device !"};
    }

    // Queues are created at the same time as the device
    // so we want to handle queues
    // from given logical device, of given queue family, of given queue index (0 since only 1 queue atm), place reference in given VkQueue
    vkGetDeviceQueue(mainDevice.logicalDevice, indices.graphicsFamily, 0, &graphicsQueue);
    vkGetDeviceQueue(mainDevice.logicalDevice, indices.presentationFamily, 0, &presentationQueue);
}

// Creates a surface between GLFW window and Vulkan to interact with each other
void VulkanRenderer::createSurface()
{
    // Create Surface (creates a surface create info struct, runs the create surface function, returns result)
    VkResult result{glfwCreateWindowSurface(instance, window.getWindow(), nullptr, &surface)};

    if (result != VK_SUCCESS)
        throw std::runtime_error{"Failed to Create a Surface !"};
}

// Returns info about surface capabilities, surface formats, and presentation modes
// If there are no surface formats or surface presentation modes then the device is not supported for Swap Chain
SwapChainDetails VulkanRenderer::getSwapChainDetails(VkPhysicalDevice device)
{

    SwapChainDetails swapChainDetails;
    // -- Capabilities --
    // Get the surface capabilities for the given surface on the given device
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &swapChainDetails.surfaceCapabilities);

    // -- Formats --
    uint32_t formatCount{0};
    vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, nullptr);

    // If formats returned, then get list of formats
    if (formatCount != 0)
    {
        swapChainDetails.surfaceFormats.resize(formatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, swapChainDetails.surfaceFormats.data());
    }

    // -- Presentation Modes --
    uint32_t presentationCount{0};
    vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentationCount, nullptr);

    // If presentation modes returned, then get list of presentation modes
    if (presentationCount != 0)
    {
        swapChainDetails.presentationModes.resize(presentationCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentationCount, swapChainDetails.presentationModes.data());
    }

    return swapChainDetails;
}

void VulkanRenderer::createSwapchain()
{
    // Get SwapChain details so we can pick best settings
    SwapChainDetails swapChainDetails{getSwapChainDetails(mainDevice.physicalDevice)};

    // find optimal surface values for our swap chain
    // 1. choose best surface format
    VkSurfaceFormatKHR surfaceFormat{selectBestSurfaceFormat(swapChainDetails.surfaceFormats)};
    // 2. choose best presentation mode
    VkPresentModeKHR presentationMode{selectBestPresentationMode(swapChainDetails.presentationModes)};
    // 3. choose swapchain image resolution/extent
    VkExtent2D extent{selectSwapExtent(swapChainDetails.surfaceCapabilities)};

    // How many images are in the swap chain?
    // Get 1 more than the minimum to allow triple buffering
    uint32_t imageCount{swapChainDetails.surfaceCapabilities.minImageCount + 1};

    // if imageCount higher than max, then clamp down to max
    // maxImageCount > 0 means no limit for image count
    // so check it before if it is greater than 0
    if (swapChainDetails.surfaceCapabilities.maxImageCount > 0 && swapChainDetails.surfaceCapabilities.maxImageCount < imageCount)
    {
        imageCount = swapChainDetails.surfaceCapabilities.maxImageCount;
    }

    // Creation information for our swap chain
    VkSwapchainCreateInfoKHR swapChainCreationInfo{};
    swapChainCreationInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    swapChainCreationInfo.surface = surface;
    swapChainCreationInfo.imageFormat = surfaceFormat.format;                                   // Swapchain format
    swapChainCreationInfo.imageColorSpace = surfaceFormat.colorSpace;                           // Swapchain colorspace
    swapChainCreationInfo.presentMode = presentationMode;                                       // Swapchain presentation mode
    swapChainCreationInfo.imageExtent = extent;                                                 // Swapchain image extent
    swapChainCreationInfo.minImageCount = imageCount;                                           // Minimum image in swapchain
    swapChainCreationInfo.imageArrayLayers = 1;                                                 // Number of layers for each image in swapchain
    swapChainCreationInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;                     // What attachment images will be used as
    swapChainCreationInfo.preTransform = swapChainDetails.surfaceCapabilities.currentTransform; // Transform to perform on swapchain images
    swapChainCreationInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;                   // How to handle blanding images with external graphics (other windows etc.)
    swapChainCreationInfo.clipped = VK_TRUE;                                                    // Whether to clip parts of image not in the view (e.g. behind another window)

    // Get queue family indices
    QueueFamilyIndices indices{getQueueFamillies(mainDevice.physicalDevice)};

    // If graphics and presentation queues are different, then swapchain must let images be shared between queues
    if (indices.graphicsFamily != indices.presentationFamily)
    {
        // Queues to share between
        uint32_t queueFamilyIndices[]{
            static_cast<uint32_t>(indices.graphicsFamily),
            static_cast<uint32_t>(indices.presentationFamily)};

        swapChainCreationInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT; // Image share handling
        swapChainCreationInfo.queueFamilyIndexCount = 2;                     // Number of queues to share images between
        swapChainCreationInfo.pQueueFamilyIndices = queueFamilyIndices;      // Array of queues to share between
    }
    else
    {
        swapChainCreationInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE; // Image share handling, exclusive to single queue
        swapChainCreationInfo.queueFamilyIndexCount = 0;                    // Number of queues to share images between
        swapChainCreationInfo.pQueueFamilyIndices = nullptr;                // Array of queues to share between
    }

    // If you decide to resize the window then, you need to destroy old swapchain and create a new one.
    swapChainCreationInfo.oldSwapchain = VK_NULL_HANDLE;

    // Create Swapchain
    if (VK_SUCCESS != vkCreateSwapchainKHR(mainDevice.logicalDevice, &swapChainCreationInfo, nullptr, &swapchain))
    {
        throw std::runtime_error("Failed to Create a Swapchain !");
    }
}

// Best format is subjective but ours will be:
// format       : VK_FORMAT_R8G8B8A8_UNORM (VK_FORMAT_B8G8R8A8_UNORM as backup)
// colorSpace   : VK_COLOR_SPACE_SRGB_NONLINEAR_KHR
VkSurfaceFormatKHR VulkanRenderer::selectBestSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &surfaceFormats)
{

    // There are actually lots of formats there. (no restrictions)
    // If all the formats are available then we just do the following condition
    // This condition means, all formats are available, we can have any.
    if (surfaceFormats.size() == 1 && surfaceFormats[0].format == VK_FORMAT_UNDEFINED)
    {
        return VkSurfaceFormatKHR{VK_FORMAT_R8G8B8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};
    }

    // if restricted, search for optimal one
    for (const auto &surfaceFormat : surfaceFormats)
    {
        // RGBA or BGRA both are common and fine.
        if ((surfaceFormat.format == VK_FORMAT_R8G8B8A8_UNORM || surfaceFormat.format == VK_FORMAT_B8G8R8A8_UNORM) && surfaceFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
        {
            return surfaceFormat;
        }
    }

    // if we can't find the format we looked for
    return surfaceFormats[0];
}

// Selects mailbox presentation if possible, FIFO otherwise
VkPresentModeKHR VulkanRenderer::selectBestPresentationMode(const std::vector<VkPresentModeKHR> &presentationModes)
{
    for (const auto &presentationMode : presentationModes)
    {
        if (presentationMode == VK_PRESENT_MODE_MAILBOX_KHR)
        {
            return presentationMode;
        }
    }

    // This one is a part of vulkan spec and always has to be available.
    // if we can't find the mode we looked for we return the following.
    return VK_PRESENT_MODE_FIFO_KHR;
}

//
VkExtent2D VulkanRenderer::selectSwapExtent(const VkSurfaceCapabilitiesKHR &surfaceCapabilities)
{

    // if current extent is at numeric limits, then extent can vary
    if (surfaceCapabilities.currentExtent.width != std::numeric_limits<std::uint32_t>::max())
    {
        return surfaceCapabilities.currentExtent;
    }

    // otherwise, it is size of the window.
    int width, height;
    // framebuffer size have the same size as the window
    glfwGetFramebufferSize(window.getWindow(), &width, &height);

    // Create new extent using window size
    // Surface also defines max and min, so make sure within boundaries by clamping value
    VkExtent2D newExtent{
        // keep the width between min-max image extent size
        std::max(surfaceCapabilities.minImageExtent.width,
                 std::min(surfaceCapabilities.maxImageExtent.width, static_cast<uint32_t>(width))),

        // keep the height between min-max image extent size
        std::max(surfaceCapabilities.minImageExtent.height,
                 std::min(surfaceCapabilities.maxImageExtent.height, static_cast<uint32_t>(height)))};

    return newExtent;
}