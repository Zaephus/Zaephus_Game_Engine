
#include "Mesh.h"

Mesh::Mesh(Device* _device, VkCommandPool* _commandPool) {
    device = _device;
    commandPool = _commandPool;
}

void Mesh::initialize() {
    createVertexBuffer();
    createIndexBuffer();
}

void Mesh::render(const VkCommandBuffer* _commandBuffer) const {

    const VkBuffer vertexBuffers[] = { vertexBuffer.buffer };
    constexpr VkDeviceSize offsets[] = { 0 };

    vkCmdBindVertexBuffers(*_commandBuffer, 0, 1, vertexBuffers,  offsets);

    vkCmdBindIndexBuffer(*_commandBuffer, indexBuffer.buffer, 0, VK_INDEX_TYPE_UINT16);

    vkCmdDrawIndexed(*_commandBuffer, static_cast<uint32_t>(indices.size()), 1, 0, 0, 0);
}

void Mesh::createVertexBuffer() {

    const std::vector<Vertex> vertexList = getVertexList();

    const VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

    Buffer stagingBuffer = Buffer(device, commandPool, bufferSize);
    stagingBuffer.create(VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, 0);
    stagingBuffer.copyData(vertexList.data());

    vertexBuffer = Buffer(device, commandPool, bufferSize);
    vertexBuffer.create(VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, 0);
    vertexBuffer.copyFromBuffer(stagingBuffer);

    stagingBuffer.destroy();

}

void Mesh::createIndexBuffer() {

    const VkDeviceSize bufferSize = sizeof(indices[0]) * indices.size();

    Buffer stagingBuffer = Buffer(device, commandPool, bufferSize);
    stagingBuffer.create(VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, 0);
    stagingBuffer.copyData(indices.data());

    indexBuffer = Buffer(device, commandPool, bufferSize);
    indexBuffer.create(VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, 0);
    indexBuffer.copyFromBuffer(stagingBuffer);

    stagingBuffer.destroy();

}

void Mesh::updateUniformBuffer() {

}

[[nodiscard]] std::vector<Vertex> Mesh::getVertexList() const {
    std::vector<Vertex> vertexList(vertices.size());
    for(size_t i = 0; i < vertexList.size(); i++) {
        vertexList[i].position = vertices[i];
        vertexList[i].color = vertexColors[i];
        vertexList[i].uv = uvs[i];
        vertexList[i].normal = Vector3::zero();
        vertexList[i].tangent = Vector3::zero();
        vertexList[i].biTangent = Vector3::zero();
    }
    return vertexList;
}