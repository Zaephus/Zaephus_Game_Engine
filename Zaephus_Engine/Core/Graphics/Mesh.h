
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

        const std::vector<Vector3> vertices;
        const std::vector<Vector3> vertexColors;
        const std::vector<Vector2> uvs;

        const std::vector<uint16_t> indices;

        Mesh(Device* _device, VkCommandPool* _commandPool);

        void initialize();
        void render(const VkCommandBuffer *_commandBuffer) const;

    private:

        Device* device;
        VkCommandPool* commandPool;

        Buffer vertexBuffer;
        Buffer indexBuffer;

        UniformBufferObject ubo;

        void createVertexBuffer();
        void createIndexBuffer();
        void updateUniformBuffer();

        [[nodiscard]] std::vector<Vertex> getVertexList() const;

};