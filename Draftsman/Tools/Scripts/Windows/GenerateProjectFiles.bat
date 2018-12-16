@echo off

:: Ensure local scope
setlocal

:: Ensure current dir
pushd %~dp0

:: CD 3 steps up to root/Draftsman
cd ../../../

:: Make Generated dir for generated project if not exist
IF NOT EXIST Generated ( MKDIR Generated )

:: Step in Generated dir
cd Generated

:: Clean cmake garbage if there
IF EXIST CMakeFiles ( rmdir /S /Q CMakeFiles )
IF EXIST cmake_install.cmake ( del cmake_install.cmake )
IF EXIST CMakeCache.txt ( del CMakeCache.txt )

:: Rebuild Project
cmake -DDRAFTSMAN_USE_CONFIG:BOOL=ON ../Modules

:: Create symbolic link to solution in root
cd ../../
IF EXIST Draftsman.sln ( del Draftsman.sln )
mklink "Draftsman.sln" "Draftsman\Generated\Draftsman.sln"
