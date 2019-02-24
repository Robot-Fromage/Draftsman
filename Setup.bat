@echo off
setlocal
pushd %~dp0

git submodule update --init Draftsman/Tools/Submodules/ProjectDependencies/ProjectDependencies
call Draftsman/Tools/Scripts/Windows/SetupHooks.bat
if not exist "VisualStudioProjectConfig.cmake" copy "Draftsman\Tools\DefaultConfig.cmake" "VisualStudioProjectConfig.cmake"
if not exist "MinGWMakefefilesConfig.cmake" copy "Draftsman\Tools\DefaultConfig.cmake" "MinGWMakefefilesConfig.cmake"
call Draftsman/Tools/Scripts/Windows/ProjectDependencies.bat -d
pause
