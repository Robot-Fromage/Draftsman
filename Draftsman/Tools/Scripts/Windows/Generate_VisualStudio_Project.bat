@echo off

:: Ensure local scope
setlocal

:: Ensure current dir
pushd %~dp0

:: CD 3 steps up to root/Draftsman
cd ../../../

:: Make Generated dir for generated project if not exist
IF NOT EXIST Generated_VisualStudio ( MKDIR Generated_VisualStudio )

:: Step in Generated dir
cd Generated_VisualStudio

:: Clean cmake garbage if there
IF EXIST CMakeFiles ( rmdir /S /Q CMakeFiles )
IF EXIST cmake_install.cmake ( del cmake_install.cmake )
IF EXIST CMakeCache.txt ( del CMakeCache.txt )

:: Rebuild Project
cmake -G "Visual Studio 15 2017 Win64" -DDRAFTSMAN_USE_CONFIG:BOOL=ON ../Source

:: Create symbolic link to solution in root
cd ../../
IF EXIST Draftsman.sln ( del Draftsman.sln )
mklink "Draftsman.sln" "Draftsman\Generated_VisualStudio\Draftsman.sln"
