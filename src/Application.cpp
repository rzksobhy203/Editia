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
    }

    Application::~Application()
    {
        glfwTerminate();
    }
}