#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>


class Window
{
private:
    GLFWwindow *window;
public:
    int width, height;
    Window();
    int init(const int width, const int height, const std::string_view &title);
    Window(const Window &rhs) = delete;
    ~Window();
    Window &operator=(const Window &rhs) = delete;

    // helper for renderer do not call it from outside
    GLFWwindow *getWindow() const { return window; }
    
    void static terminateAll() { glfwTerminate(); }
    bool shouldClose() { return glfwWindowShouldClose(window); }
    void operator()();
};

#endif