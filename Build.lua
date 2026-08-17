workspace "ProjectTemplate"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "App"

    output_bin = "%{wks.location}/Build/output"
    output_int = "%{wks.location}/Build/intermediate/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

    filter "system:windows"
        systemversion "latest"

-- Include sub-folders scripts
include "core/Core.lua"
include "App/App.lua"