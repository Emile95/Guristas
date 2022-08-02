#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Guristas 
{
	class GURISTAS_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define GURISTAS_CORE_ERROR(...) ::Guristas::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define GURISTAS_CORE_INFO(...) ::Guristas::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define GURISTAS_CORE_TRACE(...) ::Guristas::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define GURISTAS_CORE_WARN(...) ::Guristas::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define GURISTAS_CORE_FATAL(...) ::Guristas::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

#define GURISTAS_CLIENT_ERROR(...) ::Guristas::Logger::GetClientLogger()->error(__VA_ARGS__)
#define GURISTAS_CLIENT_INFO(...) ::Guristas::Logger::GetClientLogger()->info(__VA_ARGS__)
#define GURISTAS_CLIENT_TRACE(...) ::Guristas::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define GURISTAS_CLIENT_WARN(...) ::Guristas::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define GURISTAS_CLIENT_FATAL(...) ::Guristas::Logger::GetClientLogger()->fatal(__VA_ARGS__)