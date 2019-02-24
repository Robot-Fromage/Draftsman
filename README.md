# DraftsmanCore
![alt text](http://clementberthaud.com/dev/dep/Draftsman/media/com/draftsman_100.png "Draftsman")

Core Implementation for Draftsman Modular Nodal Pipeline C++ Library.

###### Dependencies:
        - Qt5.10 or greater prebuilt binaries for MinGW or MSVC
        - tinyxml2

###### Links:
https://www.qt.io/  \
https://github.com/leethomason/tinyxml2

## Requirements

#### All:
###### Hardware:
        - 64bit machine
        - Modern Graphics Card with support for OpenGL3 features
        - At least 8GB RAM

###### Software:
        - CMake 3.11.4 and greater
        - Git 2.17.0 and greater
        - A Python 3.7 or greater install available from PATH as "python3"

###### Links:
https://cmake.org/download/  \
https://git-scm.com/download/win  \
https://www.python.org/

#### Windows:
###### Software:
        - Windows 7, 8, 10 and greater
        - Visual Studio Studio 15 2017 and greater
        - Qt Visual Studio Tools Extension
        - MinGW 64 7.xx compatible with Qt prebuilt binaries

###### Links:
https://visualstudio.microsoft.com/fr/downloads/  \
https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools-19123

## Setup instructions:

#### Windows:
###### Clone:
        - git clone https://github.com/Robot-Fromage/Draftsman

###### Setup:
        - call Setup.bat

###### Configuration:
After launching Setup.bat, you will see two files appearing at the root of the repository:

        - VisualStudioProjectConfig.cmake
        - MinGWMakefefilesConfig.cmake

These files are used to override configuration according to the appropriate generator and compiler, if it's VisualStudio ( MSVC ) or MinGW ( GCC ).

        - SET( DRAFTSMAN_TINYXML2_USE_SHARED          OFF )
        - SET( DRAFTSMAN_TINYXML2_DEBUG_BIN_PATH      "default" )
        - SET( DRAFTSMAN_TINYXML2_RELEASE_BIN_PATH    "default" )
        - SET( DRAFTSMAN_TINYXML2_DEBUG_LIB_PATH      "default" )
        - SET( DRAFTSMAN_TINYXML2_RELEASE_LIB_PATH    "default" )
        - SET( DRAFTSMAN_TINYXML2_INCLUDE_PATH        "default" )
        - SET( DRAFTSMAN_BUILD_SHARED_CORE            OFF )
        - SET( DRAFTSMAN_BUILD_SHARED_GUI             OFF )
        - SET( DRAFTSMAN_BUILD_TESTS                  ON )
        - SET( DRAFTSMAN_QT_CMAKE_PATH                "default" )

Override those values for your need, specifying where to find tinyxml2 and the build options.
The paths should be ABSOLUTE paths and point to the needed tinyxml directories.
See "Cloning and Building tinyxml2" for a little bit of help on that part.
You can set separate configuration for different generators like so. Don't forget to match the Qt install path according to the target compiler.

###### Generate VisualStudio Project:
        - call Generate_VisualStudio_Project.bat
Generate_VisualStudio_Project.bat should be called each time you add or remove a file, or add a dependency, or change the paths to you tinyxml2 installation.

After the generation is done, you should see the generated project files under Draftsman/Generated_VisualStudio/

Nothing is compiled yet but you can call cmake --build . or launch the solution and build.
The binaries will be created under Draftsman/Generated_VisualStudio/Debug and Draftsman/Generated_VisualStudio/Release

Don't forget to copy the relevant dlls there to ensure the prorams finds the dependencies to QtCore, QtGUI, QtWidget, ...

You should see a symbolic link to Draftsman.sln appear at the root of the repository, if it doesn't appear check that you ran the script with admin rights.

###### Generate MinGW Makefiles:
        - call Generate_MinGW_Makefiles.bat
Generate_MinGW_Makefiles.bat should be called each time you add or remove a file, or add a dependency, or change the paths to you tinyxml2 installation.

After the generation is done, you should see the generated make files under Draftsman/Generated_MinGW/Debug/ and Draftsman/Generated_MinGW/Release/

Nothing is compiled yet but you can call cmake --build . in one of these repositories.
The binaries will be created under Draftsman/Generated_MinGW/Debug/ and Draftsman/Generated_MinGW/Release/

Don't forget to copy the relevant dlls there to ensure the prorams finds the dependencies to QtCore, QtGUI, QtWidget, ... 

## Cloning and Building tinyxml2

#### Windows:
Here are some little script samples you can use to quickly clone and build ( do this outside of the repository anywhere on your disk )

###### VisualStudio
        - mkdir build_tinyxml_MSVC
        - cd build_tinyxml_MSVC
        - cmake -G "Visual Studio 15 2017 Win64" -DBUILD_SHARED_LIBS=OFF ../tinyxml2
        - cmake --build . --config Release
        - cmake --build . --config Debug
Once it's done, you should copy the relevant paths in your Generate_VisualStudio_Project.cmake file.

Example:

        - SET( DRAFTSMAN_TINYXML2_USE_SHARED          OFF )
        - SET( DRAFTSMAN_TINYXML2_DEBUG_BIN_PATH      "W:/work/DraftsmanSystems/build_tinyxml_MSVC/Debug/tinyxml2d.dll" )
        - SET( DRAFTSMAN_TINYXML2_RELEASE_BIN_PATH    "W:/work/DraftsmanSystems/build_tinyxml_MSVC/Release/tinyxml2.dll" )
        - SET( DRAFTSMAN_TINYXML2_DEBUG_LIB_PATH      "W:/work/DraftsmanSystems/build_tinyxml_MSVC/Debug/tinyxml2d.lib" )
        - SET( DRAFTSMAN_TINYXML2_RELEASE_LIB_PATH    "W:/work/DraftsmanSystems/build_tinyxml_MSVC/Release/tinyxml2.lib" )
        - SET( DRAFTSMAN_TINYXML2_INCLUDE_PATH        "W:/work/DraftsmanSystems/tinyxml2/" )
        - SET( DRAFTSMAN_BUILD_SHARED_CORE            OFF )
        - SET( DRAFTSMAN_BUILD_SHARED_GUI             OFF )
        - SET( DRAFTSMAN_BUILD_TESTS                  ON )
        - SET( DRAFTSMAN_QT_CMAKE_PATH                "D:/QtMSVC/5.10.1/msvc2017_64/lib/cmake/" )

###### MinGW
MinGW does not generate a multi configuration project file, but it generates a set of make files per configuration, hence the process is a little more complex.

        - mkdir build_tinyxml_MinGW
        - cd build_tinyxml_MinGW
        - mkdir Release
        - mkdir Debug
        - 
        - cd Release
        - cmake -G "MinGW Makefiles" -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release ../../tinyxml2
        - cmake --build .
        - 
        - cd ..
        - cd Debug
        - cmake -G "MinGW Makefiles" -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Debug ../../tinyxml2
        - cmake --build .
Once it's done, you should copy the relevant paths in your Generate_VisualStudio_Project.cmake file.

Example:

        - SET( DRAFTSMAN_TINYXML2_USE_SHARED          OFF )
        - SET( DRAFTSMAN_TINYXML2_DEBUG_BIN_PATH      "W:/work/DraftsmanSystems/build_tinyxml_MinGW/Debug/libtinyxml2d.dll" )
        - SET( DRAFTSMAN_TINYXML2_RELEASE_BIN_PATH    "W:/work/DraftsmanSystems/build_tinyxml_MinGW/Release/libtinyxml2.dll" )
        - SET( DRAFTSMAN_TINYXML2_DEBUG_LIB_PATH      "W:/work/DraftsmanSystems/build_tinyxml_MinGW/Debug/libtinyxml2d.a" )
        - SET( DRAFTSMAN_TINYXML2_RELEASE_LIB_PATH    "W:/work/DraftsmanSystems/build_tinyxml_MinGW/Release/libtinyxml2.a" )
        - SET( DRAFTSMAN_TINYXML2_INCLUDE_PATH        "W:/work/DraftsmanSystems/tinyxml2/" )
        - SET( DRAFTSMAN_BUILD_SHARED_CORE            OFF )
        - SET( DRAFTSMAN_BUILD_SHARED_GUI             OFF )
        - SET( DRAFTSMAN_BUILD_TESTS                  ON )
        - SET( DRAFTSMAN_QT_CMAKE_PATH                "D:/QtMinGW/5.12.1/mingw73_64/lib/cmake/" )