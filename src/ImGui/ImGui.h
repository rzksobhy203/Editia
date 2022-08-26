#pragma once
#include <edpch.h>

namespace Editia
{
	namespace ImGuiLayer
    {
        class ImGuiLayer
        {
        public:
            static void onAttach();
            static void onDetach();

            static void FrameBegin();
            static void FrameEnd();

            static void DockspaceBegin();
            static void DockspaceEnd();

        private:
            ImGuiLayer() {}
            ~ImGuiLayer() {}
        };
    }
}