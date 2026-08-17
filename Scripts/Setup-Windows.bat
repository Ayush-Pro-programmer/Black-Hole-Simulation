@echo off
@REM changing directory to project root
pushd %~dp0\..

Vendor\premake\windows\premake5.exe --file=Build.lua vs2026

popd
PAUSE