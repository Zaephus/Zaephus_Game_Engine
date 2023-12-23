
#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include <vector>

#include "Core/Structs.h"
#include "Core/Math/Math.h"
#include "Core/Graphics/Vertex.h"

class Mesh {

    public:

        const std::vector<Vector3> vertices;
        const std::vector<Vector4> vertexColours;
        const std::vector<Vector2> uvs;

        const std::vector<uint16_t> indices;

        UniformBufferObject ubo;

        void initialize();
        void render();

    private:

        void createVertexBuffer();
        void createIndexBuffer();
        void updateUniformBuffer();

        const std::vector<Vertex> getVertexList();

};