workspace "Nexus"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "App"

    output_bin = "%{wks.location}/Build/output"
    output_int = "%{wks.location}/Build/intermediate/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

    filter "system:windows"
        systemversion "latest"
        buildoptions {"/utf-8"}

-- Third-party Projects
include "Core/vendor/GLFW/GLFW.lua"

-- Engine Projects
include "core/Core.lua"
include "App/App.lua"