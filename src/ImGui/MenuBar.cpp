#include <edpch.h>
#include "MenuBar.h"

#include <imgui.h>
#include <GLFW/glfw3.h>

namespace Editia
{
    namespace ImGuiLayer
    {
        namespace MenuBar
        {
            MenuBar *MenuBar::s_Instance = nullptr;

            MenuBar::MenuBar()
                : menus({NULL, NULL})
            {
                if (s_Instance != nullptr)
                {
                    LOG_ERROR("MenuBar already exists");
                    exit(EXIT_FAILURE);
                }

                LOG_TRACE("Initializing MenuBar...");
                s_Instance = this;

                Item _new = {"new",
                             nullptr,
                             false,
                             true,
                             []()
                             { LOG_INFO("Not implemented!"); }};

                Item _open = {"open",
                              nullptr,
                              false,
                              true,
                              []()
                              { LOG_INFO("Not implemented!"); }};

                Item _close = {"close",
                               nullptr,
                               false,
                               true,
                               []()
                               { glfwSetWindowShouldClose(glfwGetCurrentContext(), true); }};

                Menu File = {"File",
                             true,
                             {_new, _open, _close}};

                Menu extentions = {"extentions",
                                   true,
                                   {}};

                menus = {File, extentions};
            }

            MenuBar::~MenuBar()
            {
            }

            void MenuBar::Render()
            {
                if (ImGui::BeginMenuBar())
                {
                    for (const auto &menu : menus)
                    {
                        RenderMenu(menu);
                    }

                    ImGui::EndMenuBar();
                }
            }

            void MenuBar::RenderItem(const Item &item)
            {
                if (ImGui::MenuItem(item.label, item.shortcut, item.selected, item.enabled))
                    item.callback();
            }

            void MenuBar::RenderMenu(const Menu &menu)
            {
                const auto &contents = menu.contents;
                if (ImGui::BeginMenu(menu.label, menu.enabled))
                {
                    for (int i = 0; i < contents.size(); i++)
                    {
                        if (const Item *item = std::get_if<Item>(&contents[i]))
                        {
                            RenderItem(*item);
                        }
                        else if (const Menu *menu = std::get_if<Menu>(&contents[i]))
                        {
                            RenderMenu(*menu);
                        }
                        else
                        {
                            LOG_ERROR("Unkown type!");
                            exit(EXIT_FAILURE);
                        }
                    }

                    ImGui::EndMenu();
                }
            }
        }
    }
}