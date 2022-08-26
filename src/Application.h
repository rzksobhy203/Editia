#pragma once

namespace Editia
{
    class Application
    {
    public:
        Application();
        ~Application();

    private:
        static Application *s_Instance;
    };
}