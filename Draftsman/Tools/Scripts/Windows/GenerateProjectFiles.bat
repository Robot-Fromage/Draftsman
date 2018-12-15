@echo off

:: Ensure local scope
setlocal

:: Ensure current dir
pushd %~dp0

:: CD 3 steps up to root/Draftsman
cd ../../../

:: Make Generated dir for generated project if not exist
mkdir Generated

:: Step in Generated dir
cd Generated

:: Clean cmake garbage if there
rmdir /S /Q CMakeFiles
del cmake_install.cmake
del CMakeCache.txt

:: Rebuild Project
cmake ../Modules

:: Create symbolic link to solution in root
cd ../../
mklink "Draftsman.sln" "Draftsman\Generated\Draftsman.sln"
