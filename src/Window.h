#pragma once

#include "edpch.h"
#include <GLFW/glfw3.h>

namespace Editia
{
    struct WindowProps
    {
        int width;
        int height;
        const char *title;
    };

    class Window
    {
    public:
        Window(const char *title, int width = 800, int height = 600);
        ~Window();

        void setTitle(const char *title);

        WindowProps getWindowProps() const;
        inline GLFWwindow *getNativeWindow() const { return window; }

    private:
        const char *title;
        GLFWwindow *window;
    };
}