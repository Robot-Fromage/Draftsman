cmake_minimum_required(VERSION 3.11.0)

# Set Cache variables
SET( DRAFTSMAN_USE_CONFIG                   OFF         CACHE BOOL      "Scpecifies wether to use config files for overriding cache variables" )
SET( DRAFTSMAN_TINYXML2_USE_SHARED          OFF         CACHE BOOL      "Sets if we use a Shared version of tinyxml" )
SET( DRAFTSMAN_TINYXML2_DEBUG_BIN_PATH      "unset"     CACHE STRING    "Indicates the path to tinyxml2 debug bin" )
SET( DRAFTSMAN_TINYXML2_RELEASE_BIN_PATH    "unset"     CACHE STRING    "Indicates the path to tinyxml2release bin" )
SET( DRAFTSMAN_TINYXML2_DEBUG_LIB_PATH      "unset"     CACHE STRING    "Indicates the path to tinyxml2 debug lib" )
SET( DRAFTSMAN_TINYXML2_RELEASE_LIB_PATH    "unset"     CACHE STRING    "Indicates the path to tinyxml2 release lib" )
SET( DRAFTSMAN_TINYXML2_INCLUDE_PATH        "unset"     CACHE STRING    "Indicates the path to tinyxml2 include dir" )
SET( DRAFTSMAN_BUILD_SHARED_CORE            OFF         CACHE BOOL      "Sets if we build the library shared or static" )
SET( DRAFTSMAN_BUILD_SHARED_GUI             OFF         CACHE BOOL      "Sets if we build the library shared or static" )
SET( DRAFTSMAN_BUILD_TESTS                  ON          CACHE BOOL      "Sets if we build the library shared or static" )
SET( DRAFTSMAN_QT_CMAKE_PATH                "unset"     CACHE STRING    "Indicates the path to Qt cmake package" )

# Generate only Debug and Release configurations for all projects
set( CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE )
# Generate only x64 configurations for all projects
#set( CMAKE_GENERATOR_PLATFORM x64 )
# Get rid of cmake's ZERO_CHECK for solution
set( CMAKE_SUPPRESS_REGENERATION true )
# Set Debug postfix for all projects
set( CMAKE_DEBUG_POSTFIX d )
# Set Runtime Library for all projects
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

# Create global solution
project( Draftsman CXX )

# Read Preferences if needed
if( ${DRAFTSMAN_USE_CONFIG} )
    # Read Default Preferences
    include(${CMAKE_CURRENT_SOURCE_DIR}/../Config/DefaultProjectConfig.cmake)
    # Read Preferences Overrides if set
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../ProjectConfigOverrides.cmake)
        include(${CMAKE_CURRENT_SOURCE_DIR}/../../ProjectConfigOverrides.cmake)
    endif()
endif()

set (CMAKE_PREFIX_PATH ${DRAFTSMAN_QT_CMAKE_PATH})
set (CMAKE_AUTOMOC ON)

# Add projects
include(${CMAKE_CURRENT_SOURCE_DIR}/DraftsmanCore/CMakeLists.txt) # Depends on tinyxml
include(${CMAKE_CURRENT_SOURCE_DIR}/DraftsmanGUI/CMakeLists.txt) # Depends on DraftsmanCore

if( ${DRAFTSMAN_BUILD_TESTS} )
    include(${CMAKE_CURRENT_SOURCE_DIR}/Test_DraftsmanCore/CMakeLists.txt) # Depends on DraftsmanCore
    include(${CMAKE_CURRENT_SOURCE_DIR}/Test_DraftsmanGUI/CMakeLists.txt) # Depends on DraftsmanGUI
endif()

set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DraftsmanCore )
