#include "edpch.h"
#include "Application.h"

int main(void)
{
    // initializing our logging system
    // log defines
    // LOG_INFO(...)
    // LOG_WARN(...)
    // LOG_ERROR(...)
    // LOG_TRACE(...)
    Editia::Log::init();

    Editia::Application app;

    // Render window
    app.Render();

	return 0;
}