
#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include "Core/Structs.h"
#include "Core/Math/Math.h"
#include "Core/Graphics/Vertex.h"

class Mesh {

    public:

        const std::vector<Vertex> vertices = {
            { { -0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f }, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f} },
            { { 0.5f,  -0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f} },
            { { 0.5f,  0.5f,  0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f }, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f} },
            { { -0.5f, 0.5f,  0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f}, { 0.0f, 0.0f, 0.0f} }
        };

        const std::vector<uint16_t> indices = {
            0, 1, 2, 2, 3, 0
        };

        UniformBufferObject ubo;

    private:

        void createVertexBuffer();
        void createIndexBuffer();
        void updateUniformBuffer();

};