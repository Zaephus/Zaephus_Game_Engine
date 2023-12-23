
#include "Buffer.h"
#include <iostream>

Buffer::Buffer() {
    device = nullptr;
    commandPool = nullptr;
    bufferSize = 0;
}

Buffer::Buffer(Device* _device, VkCommandPool* _commandPool, VkDeviceSize _size) {
    device = _device;
    commandPool = _commandPool;
    bufferSize = _size;
}

void Buffer::create(VkBufferUsageFlags _usage, VkMemoryPropertyFlags _properties, VkDeviceSize _offset) {

    VkBufferCreateInfo bufferInfo {
        .sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
        .size = bufferSize,
        .usage = _usage,
        .sharingMode = VK_SHARING_MODE_EXCLUSIVE
    };

    if(vkCreateBuffer(device->logicalDevice, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create buffer!");
    }

    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(device->logicalDevice, buffer, &memRequirements);

    // TODO: Remove temporary times 2 in allocationSize.
    VkMemoryAllocateInfo allocInfo{
        .sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
        .allocationSize = memRequirements.size * 2,
        .memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, _properties)
    };

    if(vkAllocateMemory(device->logicalDevice, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
        throw std::runtime_error("Failed to allocate buffer memory!");
    }

    vkBindBufferMemory(device->logicalDevice, buffer, bufferMemory, _offset);

}

void Buffer::destroy() {
    vkDestroyBuffer(device->logicalDevice, buffer, nullptr);
    vkFreeMemory(device->logicalDevice, bufferMemory, nullptr);
}

void Buffer::bindData(void* _data) {
    vkMapMemory(device->logicalDevice, bufferMemory, 0, bufferSize, 0, &_data);
}

void Buffer::copyData(const void* _data) {
    void* tempData;
    vkMapMemory(device->logicalDevice, bufferMemory, 0, bufferSize, 0, &tempData);
    memcpy(tempData, _data, (size_t)bufferSize);
    vkUnmapMemory(device->logicalDevice, bufferMemory);
}

void Buffer::copyFrom(Buffer &_sourceBuffer) {

    VkCommandBuffer commandBuffer = beginSingleTimeCommands();

    VkBufferCopy copyRegion{
        .srcOffset = 0,
        .dstOffset = 0,
        .size = bufferSize
    };

    vkCmdCopyBuffer(commandBuffer, _sourceBuffer.buffer, buffer, 1, &copyRegion);

    endSingleTimeCommands(commandBuffer);
}

VkCommandBuffer Buffer::beginSingleTimeCommands() {
    
    VkCommandBufferAllocateInfo allocInfo{
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        .commandPool = *commandPool,
        .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY,
        .commandBufferCount = 1
    };

    VkCommandBuffer commandBuffer;
    vkAllocateCommandBuffers(device->logicalDevice, &allocInfo, &commandBuffer);

    VkCommandBufferBeginInfo beginInfo {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
        .flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT
    };

    vkBeginCommandBuffer(commandBuffer, &beginInfo);

    return commandBuffer;

}

void Buffer::endSingleTimeCommands(VkCommandBuffer _commandBuffer) {

    vkEndCommandBuffer(_commandBuffer);

    VkSubmitInfo submitInfo {
        .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
        .commandBufferCount = 1,
        .pCommandBuffers = &_commandBuffer
    };

    vkQueueSubmit(device->graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
    vkQueueWaitIdle(device->graphicsQueue);

    vkFreeCommandBuffers(device->logicalDevice, *commandPool, 1, &_commandBuffer);

}

uint32_t Buffer::findMemoryType(uint32_t _typeFilter, VkMemoryPropertyFlags _properties) {

    VkPhysicalDeviceMemoryProperties memProperties;
    vkGetPhysicalDeviceMemoryProperties(device->physicalDevice, &memProperties);

    for(uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
        if((_typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & _properties) == _properties) {
            return i;
        }
    }

    throw std::runtime_error("Failed to find suitable memory type!");

}