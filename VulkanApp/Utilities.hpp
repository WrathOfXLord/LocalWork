#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_

const std::vector<const char *> deviceExtensions {VK_KHR_SWAPCHAIN_EXTENSION_NAME};


// Indices (location) of queue famillies (if they exist at all)
struct QueueFamilyIndices {
    // Location of Graphics Queue Family
    int graphicsFamily {-1};
    // Location of Presentation Queue Family
    int presentationFamily {-1};

    // check if queue famillies are valid
    bool isValid() {
        return graphicsFamily >= 0 && presentationFamily >= 0;
    }
};

// Structure that stores information about surface capabilities, surface formats and presentation modes for Swap Chain
struct SwapChainDetails {
    // Surface properties, e.g. image size/extent
    VkSurfaceCapabilitiesKHR surfaceCapabilities;
    // Surface image formats, e.g. RGBA and size of each color
    std::vector<VkSurfaceFormatKHR> surfaceFormats;
    // How images should be presented to screen
    std::vector<VkPresentModeKHR> presentationModes;
};

#endif