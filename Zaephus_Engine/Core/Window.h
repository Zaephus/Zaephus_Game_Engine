
#pragma once

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>

#include <string>

class Window {

public:

    uint16_t width;
    uint16_t height;

    std::string title;

    Window(uint16_t _width, uint16_t _height, std::string _title);

private:

    GLFWwindow *window;

    bool framebufferResized = false;

    void initWindow();

    static void framebufferResizeCallback(GLFWwindow* _window, int _width, int _height);

};