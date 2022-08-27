#pragma once

#include <edpch.h>

namespace Editia
{
	namespace ImGuiLayer
    {
        namespace MenuBar
        {
            struct Item
            {
                const char *label;
                const char *shortcut;
                bool selected, enabled;
                std::function<void()> callback;
            };

            struct Menu
            {
                const char *label;
                bool enabled;
                std::vector<std::variant<Item, Menu>> contents;
            };

            class MenuBar
            {
            public:
                MenuBar();
                ~MenuBar();

                void Render();

                inline std::array<Menu, 2> &getMenus() { return menus; }
                inline const std::array<Menu, 2> &getMenus() const { return menus; }

                inline static MenuBar &get() { return *s_Instance; }

            private:
                void RenderItem(const Item &item);
                void RenderMenu(const Menu &menu);

            private:
                std::array<Menu, 2> menus;

            private:
                static MenuBar *s_Instance;
            };
        }
    }
}