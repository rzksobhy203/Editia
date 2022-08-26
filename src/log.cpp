#include "edpch.h"
#include "log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Editia
{
    std::shared_ptr<spdlog::logger> Log::s_Logger = nullptr;

    void Log::init()
    {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Editia.log", true));

        logSinks[0]->set_pattern("%^[%T] [%l] %v%$");
        logSinks[1]->set_pattern("[%T] [%l] %v");

        s_Logger = std::make_shared<spdlog::logger>("EDITIA", logSinks.begin(), logSinks.end());
        spdlog::register_logger(s_Logger);
        s_Logger->set_level(spdlog::level::trace);
        s_Logger->flush_on(spdlog::level::trace);
    }
}