
#include "Window.h"

Window::Window(uint16_t _width, uint16_t _height, std::string _title) {
    width = _width;
    height = _height;

    title = _title;

    initWindow();
}

void Window::initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);

}

void Window::framebufferResizeCallback(GLFWwindow* _window, int _width, int _height) {
    auto w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(_window));
    w->framebufferResized = true;
}
