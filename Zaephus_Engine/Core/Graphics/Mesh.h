
#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include <vector>

#include "Core/Structs.h"
#include "Core/Device.h"
#include "Core/Buffer.h"
#include "Core/Math/Math.h"
#include "Core/Graphics/Vertex.h"

class Mesh {

    public:

        std::vector<Vector3> vertexPositions;
        std::vector<Vector3> vertexColors;
        std::vector<Vector2> uvs;

        Buffer vertexBuffer;
        Buffer indexBuffer;

        std::vector<uint16_t> indices;

        Mesh(Device* _device, VkCommandPool* _commandPool);

        void initialize();
        void render(const VkCommandBuffer *_commandBuffer) const;
        void cleanup();

    private:

        Device* device;
        VkCommandPool* commandPool;

        void createVertexBuffer();
        void createIndexBuffer();

        [[nodiscard]] std::vector<Vertex> getVertices() const;

};