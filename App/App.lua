project "App"
    kind "ConsoleApp"
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
        "../Core/src"
    }

    links {
        "Core"
    }

    dependson {
        "Core"
    }

    filter "configurations:Debug"
        defines "APP_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "APP_RELEASE"
        runtime "Release"
        optimize "on"