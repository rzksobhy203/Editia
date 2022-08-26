#include "edpch.h"
#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Editia
{
    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        if (s_Instance != nullptr)
        {
            LOG_ERROR("Application already exists!");
            exit(EXIT_FAILURE);
        }

        LOG_TRACE("Initializing Application...");
        s_Instance = this;

        LOG_TRACE("Initializing GLFW...");
        if (!glfwInit())
        {
            LOG_ERROR("Failed to initialize GLFW!");
            exit(EXIT_FAILURE);
        }

        glfwSetErrorCallback([](int error_code, const char *description)
        {
            LOG_ERROR("GLFW: ({0:x}) {1}", error_code, description);
            exit(EXIT_FAILURE);
        });

        window = std::make_unique<Window>("Editia");

        LOG_TRACE("Initializing GLAD...");
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_ERROR("Failed to initialize GLAD!");
            exit(EXIT_FAILURE);
        }
    }

    Application::~Application()
    {
        window.reset();
        glfwTerminate();
    }

    void Application::Render()
    {
        GLFWwindow *window = this->window->getNativeWindow();
        while (!glfwWindowShouldClose(window))
        {
            // TODO: handle events
            glfwPollEvents();

            glfwSwapBuffers(window);
        }
    }
}