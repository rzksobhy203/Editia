#pragma once

#include <memory>

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Editia
{
    class Log
    {
    public:
        static void init();

        static std::shared_ptr<spdlog::logger> &getLogger() { return s_Logger; }

    private:
        static std::shared_ptr<spdlog::logger> s_Logger;

    private:
        Log() {}
        ~Log() {}
    };
}

// Log defints
#define LOG_INFO(...)  ::Editia::Log::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)  ::Editia::Log::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Editia::Log::getLogger()->error(__VA_ARGS__)
#define LOG_TRACE(...) ::Editia::Log::getLogger()->trace(__VA_ARGS__)