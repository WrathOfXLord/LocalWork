#include "Window.hpp"


Custom::Window::Window(int width, int height, std::string name)
: width {width}, height {height}, name {name} {
    initWindow();
}

void Custom::Window::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
}

Custom::Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}