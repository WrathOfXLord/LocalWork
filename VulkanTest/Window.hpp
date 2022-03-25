#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace Custom
{
    class Window
    {
    private:
        const int width, height;
        std::string name;
        GLFWwindow *window;

        void initWindow();

    public:
        Window(int width, int height, std::string name = {"Window"});
        Window(const Window &rhs) = delete;
        Window &operator=(const Window &rhs) = delete;
        ~Window();

        bool shouldClose() { return glfwWindowShouldClose(window); }
    };
}

#endif