#include "Window.hpp"
#include <iostream>

Window::Window()
: window {nullptr}, width {}, height {} {

}

int Window::init(const int width, const int height, const std::string_view &title) {
    try {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::operator()() {
    while(!this->shouldClose()) {
        glfwPollEvents();
    }
}