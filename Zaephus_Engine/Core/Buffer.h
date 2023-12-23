
#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include "Device.h"

class Buffer {

    public:

        VkBuffer buffer;

        Buffer();
        Buffer(Device* _device, VkCommandPool* _commandPool, VkDeviceSize _size);
        
        void create(VkBufferUsageFlags _usage, VkMemoryPropertyFlags _properties, VkDeviceSize _offset);
        void destroy();

        void bindData(void* _data);
        void copyData(const void* _data);
        void copyFrom(Buffer& _sourceBuffer);

    private:

        Device* device;
        VkCommandPool* commandPool;
        VkDeviceSize bufferSize;
        VkDeviceMemory bufferMemory;
        
        VkCommandBuffer beginSingleTimeCommands();
        void endSingleTimeCommands(VkCommandBuffer _commandBuffer);

        uint32_t findMemoryType(uint32_t _typeFilter, VkMemoryPropertyFlags _properties);

};