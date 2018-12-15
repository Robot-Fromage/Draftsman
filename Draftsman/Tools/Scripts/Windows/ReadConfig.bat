@echo off

:: Ensure current dir
pushd %~dp0

:: CD 4 steps up to root
cd ../../../../

:: Read default config values from file
set config_file=DraftsmanCore\Config\DefaultProjectConfig.ini
if not exist "DraftsmanCore\Config\DefaultProjectConfig.ini" goto Error_DefaultConfig_NotFound
@call:ini DC_BUILD_TINYXML2 DC_BUILD_TINYXML2 %config_file%
@call:ini DC_TINYXML2_BUILD_SHARED DC_TINYXML2_BUILD_SHARED %config_file%
@call:ini DC_TINYXML2_CLONE_PARENT_PATH DC_TINYXML2_CLONE_PARENT_PATH %config_file%
@call:ini DC_TINYXML2_DEBUG_BIN_PATH DC_TINYXML2_DEBUG_BIN_PATH %config_file%
@call:ini DC_TINYXML2_RELEASE_BIN_PATH DC_TINYXML2_RELEASE_BIN_PATH %config_file%
@call:ini DC_TINYXML2_DEBUG_LIB_PATH DC_TINYXML2_DEBUG_LIB_PATH %config_file%
@call:ini DC_TINYXML2_RELEASE_LIB_PATH DC_TINYXML2_RELEASE_LIB_PATH %config_file%
@call:ini DC_TINYXML2_INCLUDE_PATH DC_TINYXML2_INCLUDE_PATH %config_file%
@call:ini DC_BUILD_SHARED DC_BUILD_SHARED %config_file%

:: Override config values if set
set config_file=ProjectConfig.ini
if exist "ProjectConfig.ini" (
@call:ini DC_BUILD_TINYXML2 DC_BUILD_TINYXML2 %config_file%
@call:ini DC_TINYXML2_BUILD_SHARED DC_TINYXML2_BUILD_SHARED %config_file%
@call:ini DC_TINYXML2_CLONE_PARENT_PATH DC_TINYXML2_CLONE_PARENT_PATH %config_file%
@call:ini DC_TINYXML2_DEBUG_BIN_PATH DC_TINYXML2_DEBUG_BIN_PATH %config_file%
@call:ini DC_TINYXML2_RELEASE_BIN_PATH DC_TINYXML2_RELEASE_BIN_PATH %config_file%
@call:ini DC_TINYXML2_DEBUG_LIB_PATH DC_TINYXML2_DEBUG_LIB_PATH %config_file%
@call:ini DC_TINYXML2_RELEASE_LIB_PATH DC_TINYXML2_RELEASE_LIB_PATH %config_file%
@call:ini DC_TINYXML2_INCLUDE_PATH DC_TINYXML2_INCLUDE_PATH %config_file%
@call:ini DC_BUILD_SHARED DC_BUILD_SHARED %config_file%
)

:: End
popd
goto :EOF

:Error_DefaultConfig_NotFound
echo ExternalDependencies ERROR: DraftsmanCore\Config\DefaultProjectConfig.ini not found
pause
exit /B 1

:: Short utility to read inside a ini file
:ini
@for /f "tokens=2 delims==" %%a in ('find "%~1=" %~3') do @set %~2=%%a
@goto:eof
