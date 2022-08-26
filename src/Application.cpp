#include "edpch.h"
#include "Application.h"

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
    }

    Application::~Application()
    {
    }
}