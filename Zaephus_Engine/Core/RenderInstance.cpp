
#include "RenderInstance.h"

RenderInstance::RenderInstance() {
    renderingDebugger = nullptr;
}
RenderInstance::RenderInstance(RenderDebug* _renderingDebugger) {
    renderingDebugger = _renderingDebugger;
}

void RenderInstance::initialize(bool _enableValidationLayers) {

    // TODO: Remove renderingDebugger dependency here
    if(_enableValidationLayers && !renderingDebugger->checkValidationLayerSupport()) {
        throw std::runtime_error("Validation layers requested, but not available!");
    }

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "Zaephus Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    auto extensions = getRequiredExtensions(_enableValidationLayers);
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
    if(_enableValidationLayers) {
        // TODO: Remove renderingDebugger dependency here
        createInfo.enabledLayerCount = static_cast<uint32_t>(renderingDebugger->validationLayers.size());
        createInfo.ppEnabledLayerNames = renderingDebugger->validationLayers.data();

        renderingDebugger->populateDebugMessengerCreateInfo(debugCreateInfo);
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
    }
    else {
        createInfo.enabledLayerCount = 0;

        createInfo.pNext = nullptr;
    }

    if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create instance!");
    }

}

void RenderInstance::cleanup() {
    vkDestroyInstance(instance, nullptr);
}

std::vector<const char*> RenderInstance::getRequiredExtensions(bool _enableValidationLayers) {

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if(_enableValidationLayers) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return extensions;

}