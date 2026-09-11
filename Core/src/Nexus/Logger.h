#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Nexus {

	class NEXUS_API Logger
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

// core log macros!
#define NX_CORE_TRACE(...)		::Nexus::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define NX_CORE_INFO(...)		::Nexus::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define NX_CORE_WARN(...)		::Nexus::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define NX_CORE_ERROR(...)		::Nexus::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define NX_CORE_CRITICAL(...)	::Nexus::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// client log macros!
#define NX_TRACE(...)			::Nexus::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define NX_INFO(...)			::Nexus::Logger::GetClientLogger()->info(__VA_ARGS__)
#define NX_WARN(...)			::Nexus::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define NX_ERROR(...)			::Nexus::Logger::GetClientLogger()->error(__VA_ARGS__)
#define NX_CRITICAL(...)		::Nexus::Logger::GetClientLogger()->critical(__VA_ARGS__)