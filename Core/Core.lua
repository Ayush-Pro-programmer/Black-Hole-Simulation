project "Core"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir (output_bin)
    objdir (output_int)

    pchheader "nxpch.h"
    pchsource "src/nxpch.cpp"

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src",
        "vendor/spdlog/include",
        "vendor/GLFW/include"
    }

    links {
        "GLFW"
    }

    defines {
        "NX_PLATFORM_WINDOWS",
        "NX_BUILD_DLL"
    }

    filter "system:windows"
        links {
            "opengl32.lib"
        }

    filter "configurations:Debug"
        defines "CORE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "CORE_RELEASE"
        runtime "Release"
        optimize "on"