project "Core"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir (output_bin)
    objdir (output_int)

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src"
    }

    defines {
        "CORE_BUILD_DLL"
    }

    filter "configurations:Debug"
        defines "CORE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "CORE_RELEASE"
        runtime "Release"
        optimize "on"