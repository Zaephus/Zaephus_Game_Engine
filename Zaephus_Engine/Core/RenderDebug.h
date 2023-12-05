
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iosfwd>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <cstring>

class RenderDebug {

public:

	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};

	RenderDebug(VkInstance* _instance);
	void cleanup();

	void setupDebugMessenger();

	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	bool checkValidationLayerSupport();

private:

	VkInstance* instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	VkResult createDebugUtilsMessengerEXT(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator);
	void destroyDebugUtilsMessengerEXT(const VkAllocationCallbacks* pAllocator);

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

};