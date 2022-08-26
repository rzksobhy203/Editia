#include "Window.h"

namespace Editia
{
    Window::Window(const char *title, int width /*= 800*/, int height /*= 600*/)
        : title(title)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        LOG_TRACE("Creating a window...");
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!window)
        {
            LOG_ERROR("Failed to create window!");
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
    }

    void Window::setTitle(const char *title)
    {
        this->title = title;
        glfwSetWindowTitle(window, title);
    }

    WindowProps Window::getWindowProps() const
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        return {width, height, title};
    }
}