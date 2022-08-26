#pragma once

#include "edpch.h"
#include <GLFW/glfw3.h>

namespace Editia
{
    class Window
    {
    public:
        Window(const char *title, int width = 800, int height = 600);
        ~Window();

        void setTitle(const char *title);

        inline const char *getTitle() const { return title; }
        inline int getWidth() const { return width; }
        inline int getHeight() const { return height; }
        inline GLFWwindow *getNativeWindow() const { return window; }

    private:
        const char *title;
        int width, height;
        GLFWwindow *window;
    };
}