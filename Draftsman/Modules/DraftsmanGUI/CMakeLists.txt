cmake_minimum_required( VERSION 3.13.2 )

file(
    GLOB_RECURSE
    source_list
    RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "DraftsmanGUI/Include/*"
    "DraftsmanGUI/Source/*"
)

add_library( DraftsmanGUI ${source_list} )

#IF( ${DC_TINYXML2_BUILD_SHARED} EQUAL "OFF" )
#    target_link_libraries (
#        DraftsmanCore
#        debug ${DC_TINYXML2_DEBUG_BIN_PATH}tinyxml2d.dll
#        optimized ${DC_TINYXML2_RELEASE_BIN_PATH}tinyxml2.dll
#    )
#    target_link_libraries (
#        DraftsmanCore
#        debug ${DC_TINYXML2_DEBUG_LIB_PATH}tinyxml2d.lib
#        optimized ${DC_TINYXML2_RELEASE_LIB_PATH}tinyxml2.lib
#    )
#ELSE()
#    target_link_libraries (
#        DraftsmanCore
#        debug ${DC_TINYXML2_DEBUG_LIB_PATH}tinyxml2d.lib
#        optimized ${DC_TINYXML2_RELEASE_LIB_PATH}tinyxml2.lib
#    )
#ENDIF()

target_include_directories(
    DraftsmanGUI
    PUBLIC
    "DraftsmanGUI/Include/"
    PRIVATE
    "DraftsmanGUI/Source/DraftsmanGUI/"
)

# For MSVC parse pretty filter names
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
