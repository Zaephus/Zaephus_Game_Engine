
#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include "RenderDebug.h"

class RenderInstance {

    public:

        VkInstance instance;

        RenderInstance();
        RenderInstance(RenderDebug* _renderingDebugger);

        void initialize(bool _enableValidationLayers);
        void cleanup();


    private:

        RenderDebug* renderingDebugger;

        std::vector<const char*> getRequiredExtensions(bool _enableValidationLayers);

};