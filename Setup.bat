@echo off
setlocal
pushd %~dp0

git submodule init Draftsman/Tools/Submodules/ProjectDependencies/ProjectDependencies
REM git submodule init Draftsman/Tools/Submodules/ProjectHooks/ProjectHooks
call Draftsman/Tools/Scripts/Windows/SetupHooks.bat
copy "Draftsman\Config\DefaultConfig.cmake" "VisualStudioProjectConfig.cmake"
copy "Draftsman\Config\DefaultConfig.cmake" "MinGWMakefefilesConfig.cmake"
REM call Draftsman/Tools/Scripts/Windows/ProjectDependencies.bat -d
pause
