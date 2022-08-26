#pragma once

#include "Window.h"

namespace Editia
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Render();

        inline static Application &get() { return *s_Instance; }
        inline const std::unique_ptr<Window> &getWindow() const { return window; }

    private:
        std::unique_ptr<Window> window;

    private:
        static Application *s_Instance;
    };
}