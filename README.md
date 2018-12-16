# DraftsmanCore
![alt text](http://clementberthaud.com/dev/dep/Draftsman/media/com/draftsman_100.png "Draftsman")

Core Implementation for Draftsman Modular Nodal Pipeline C++ Library.

###### Relies on:
        - tinyxml2

## Requirements for Windows:

###### Hardware:
        - 64bit machine

###### Software:
        - Windows 7, 8, 10
        - CMake 3.0 or greater
        - Git
        - Visual Studio ( Tested for Visual Studio 15 2017 )

###### Links:
https://cmake.org/download/  \
https://git-scm.com/download/win  \
https://visualstudio.microsoft.com/fr/downloads/

## Setup instructions for Windows:

###### Clone:
        - git clone https://github.com/Robot-Fromage/DraftsmanCore

###### Setup:
        - call Setup.bat

###### Configuration:
You will see a ProjectConfigOverrides.cmake file appearing at the root of the repository.
        -SET( DRAFTSMAN_TINYXML2_USE_SHARED          OFF )
        -SET( DRAFTSMAN_TINYXML2_DEBUG_BIN_PATH      "default" )
        -SET( DRAFTSMAN_TINYXML2_RELEASE_BIN_PATH    "default" )
        -SET( DRAFTSMAN_TINYXML2_DEBUG_LIB_PATH      "default" )
        -SET( DRAFTSMAN_TINYXML2_RELEASE_LIB_PATH    "default" )
        -SET( DRAFTSMAN_TINYXML2_INCLUDE_PATH        "default" )
        -SET( DRAFTSMAN_BUILD_SHARED_CORE            OFF )
        -SET( DRAFTSMAN_BUILD_SHARED_GUI             OFF )
        -SET( DRAFTSMAN_BUILD_TESTS                  ON )
Override those values for your need, specifying where to find tinyxml2 and the build options.
The paths should be ABSOLUTE paths and point to the needed tinyxml directories.
See "Cloning and Building tinyxml2" for a little bit of help on that part.

###### Generate Visual Studio Solution:
        - call GenerateProjectFiles.bat
GenerateProjectFiles.bat should be called each time you add or remove a file, or add a dependency, or change the paths to you tinyxml2 installation.

## Cloning and Building tinyxml2
Here is a little script sample you can use to quickly clone and build
    -git clone https://github.com/leethomason/tinyxml2
    -mkdir build_tinyxml
    -cd build_tinyxml
    -cmake -G "Visual Studio 15 2017 Win64" -DBUILD_SHARED_LIBS=OFF ../tinyxml2
    -cmake --build . --config Release
    -cmake --build . --config Debug
Once it's done, you should copy the relevant paths in your PRojectConfigOverrides.cmake file.
