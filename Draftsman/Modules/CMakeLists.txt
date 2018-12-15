cmake_minimum_required(VERSION 3.11.0)

# Set Cache variables
SET( DRAFTSMAN_TINYXML2_USE_SHARED          OFF     CACHE BOOL      "Sets if we use a Shared version of tinyxml" )
SET( DRAFTSMAN_TINYXML2_DEBUG_BIN_PATH      ""      CACHE STRING    "Indicates the path to debug bin" )
SET( DRAFTSMAN_TINYXML2_RELEASE_BIN_PATH    ""      CACHE STRING    "Indicates the path to release bin" )
SET( DRAFTSMAN_TINYXML2_DEBUG_LIB_PATH      ""      CACHE STRING    "Indicates the path to debug lib" )
SET( DRAFTSMAN_TINYXML2_RELEASE_LIB_PATH    ""      CACHE STRING    "Indicates the path to release lib" )
SET( DRAFTSMAN_TINYXML2_INCLUDE_PATH        ""      CACHE STRING    "Indicates the path to include dir" )
SET( DRAFTSMAN_BUILD_SHARED_CORE            OFF     CACHE BOOL      "Sets if we build the library shared or static" )
SET( DRAFTSMAN_BUILD_SHARED_GUI             OFF     CACHE BOOL      "Sets if we build the library shared or static" )
SET( DRAFTSMAN_BUILD_TESTS                  ON      CACHE BOOL      "Sets if we build the library shared or static" )

# Generate only Debug and Release configurations
set( CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE )
# Generate only x64 configurations
set( CMAKE_GENERATOR_PLATFORM x64 )
# Get rid of cmake's ZERO_CHECK
set( CMAKE_SUPPRESS_REGENERATION true )
# Set Debug postfix
set( CMAKE_DEBUG_POSTFIX d )
# Set Runtime Library
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

# Create global solution
project( Draftsman CXX )

# Add projects
include(${CMAKE_CURRENT_SOURCE_DIR}/DraftsmanCore/CMakeLists.txt) # Depends on tinyxml
include(${CMAKE_CURRENT_SOURCE_DIR}/DraftsmanGUI/CMakeLists.txt) # Depends on DraftsmanCore
include(${CMAKE_CURRENT_SOURCE_DIR}/Test_DraftsmanCore/CMakeLists.txt) # Depends on DraftsmanCore
include(${CMAKE_CURRENT_SOURCE_DIR}/Test_DraftsmanGUI/CMakeLists.txt) # Depends on DraftsmanGUI

set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DraftsmanCore )
