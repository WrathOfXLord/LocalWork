#include "App.hpp"

void Custom::App::run() {
    while(!window.shouldClose()) {
        glfwPollEvents();
    }
}