//BOOK PG - 46
#include <stdexcept>
#define GLFW_INCLUDE_VULKAN
#include "vulkan/vulkan.h"
#include "GLFW/glfw3.h"
#include "vulkan/vulkan_core.h"
#include <exception>
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <stdlib.h>

class HelloTriangleApplication {
    public:
        void run(){
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();
        }

    private:
        const uint32_t WIDTH = 800;
        const uint32_t HEIGHT = 600;
        
        GLFWwindow* window;
        VkInstance instance;

        void initWindow(){
            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow(WIDTH , HEIGHT, "Vulkan", nullptr, nullptr);
        }

        void initVulkan(){
            createInstance();
        }

        void createInstance(){
            VkApplicationInfo appInfo{};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pApplicationName = "Hello Triangle";
            appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.pEngineName = "JVGE";
            appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.apiVersion = VK_API_VERSION_1_3;

            VkInstanceCreateInfo createinfo{};
            createinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createinfo.pApplicationInfo = &appInfo;

            uint32_t glfwExtensionCount = 0;
            const char** glfwExtensions;

            glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

            createinfo.enabledExtensionCount = glfwExtensionCount;
            createinfo.ppEnabledExtensionNames = glfwExtensions;
            createinfo.enabledLayerCount = 0;

            if (vkCreateInstance(&createinfo, nullptr, &instance) != VK_SUCCESS) {
                throw std::runtime_error("failed to create instance!");
            }

        }

        void mainLoop(){
            while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
            }
        }

        void cleanup(){
            glfwDestroyWindow(window);

            glfwTerminate();
        }

};

int main(){
    HelloTriangleApplication app;
    std::cout << "JVGE HELLO TRIANGLE\n";

    try{
    
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
