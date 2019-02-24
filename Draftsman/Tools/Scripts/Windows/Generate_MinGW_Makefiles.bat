@echo off

:: Ensure local scope
setlocal

:: Ensure current dir
pushd %~dp0

:: CD 3 steps up to root/Draftsman
cd ../../../

:: Make Generated dir for generated project if not exist
IF NOT EXIST Generated_MinGW ( MKDIR Generated_MinGW )

:: Step in Generated dir
cd Generated_MinGW

IF NOT EXIST Release ( MKDIR Release )
IF NOT EXIST Debug ( MKDIR Debug )

cd Release
:: Clean cmake garbage if there
IF EXIST CMakeFiles ( rmdir /S /Q CMakeFiles )
IF EXIST cmake_install.cmake ( del cmake_install.cmake )
IF EXIST CMakeCache.txt ( del CMakeCache.txt )
:: Rebuild Project
cmake -G "MinGW Makefiles" -DDRAFTSMAN_USE_CONFIG:BOOL=ON -DCMAKE_BUILD_TYPE=Release ../../Modules

cd ..
cd Debug
:: Clean cmake garbage if there
IF EXIST CMakeFiles ( rmdir /S /Q CMakeFiles )
IF EXIST cmake_install.cmake ( del cmake_install.cmake )
IF EXIST CMakeCache.txt ( del CMakeCache.txt )
:: Rebuild Project
cmake -G "MinGW Makefiles" -DDRAFTSMAN_USE_CONFIG:BOOL=ON -DCMAKE_BUILD_TYPE=Debug ../../Modules