#include <iostream>
#include <cstdlib>
#include "App.hpp"
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>



int main()
{
    Custom::App app {};

    try {
        app.run();
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << "\n";
        return EXIT_FAILURE;
    }

    uint32_t extensionCount {0};
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::cout << "Extension count: " << extensionCount << "\n";

    glm::mat4 testMat {1.0f};
    glm::vec4 testVec {1.0f};
    auto result = testMat * testVec;
        

    return EXIT_SUCCESS;
}