
#pragma once

#include <vulkan/vulkan.h>

#include <vector>
#include <stdexcept>
#include <set>

#include "RenderDebug.h"
#include "Structs.h"

const std::vector<const char*> deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

class Device {

    public:

        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkDevice logicalDevice;

        VkQueue graphicsQueue;
        VkQueue presentQueue;

        SwapchainSupportDetails swapchainSupportDetails;
        QueueFamilyIndices queueFamilyIndices;

        Device(VkInstance* _instance, RenderDebug* _renderingDebugger, VkSurfaceKHR* _surface);

        void initialize(bool _enableValidationLayers);
        void cleanup();

    private:

        VkInstance* instance;
        RenderDebug* renderingDebugger;
        VkSurfaceKHR* surface;

        void pickPhysicalDevice();
        void createLogicalDevice(bool _enableValidationLayers);
        bool isDeviceSuitable(VkPhysicalDevice _device);
        bool checkDeviceExtensionSupport(VkPhysicalDevice _device);
        SwapchainSupportDetails querySwapchainSupport(VkPhysicalDevice _device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice _device);

};