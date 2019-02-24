cmake_minimum_required( VERSION 3.13.2 )

file(
    GLOB_RECURSE
    source_list
    RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "DraftsmanCore/Include/*"
    "DraftsmanCore/Source/*"
)

add_library( DraftsmanCore ${source_list} )

IF( ${DRAFTSMAN_TINYXML2_USE_SHARED} )
    target_link_libraries (
        DraftsmanCore
        PUBLIC
        debug ${DRAFTSMAN_TINYXML2_DEBUG_BIN_PATH}
        optimized ${DRAFTSMAN_TINYXML2_RELEASE_BIN_PATH}
    )
    target_link_libraries (
        DraftsmanCore
        PUBLIC
        debug ${DRAFTSMAN_TINYXML2_DEBUG_LIB_PATH}
        optimized ${DRAFTSMAN_TINYXML2_RELEASE_LIB_PATH}
    )
ELSE()
    target_link_libraries (
        DraftsmanCore
        PUBLIC
        debug ${DRAFTSMAN_TINYXML2_DEBUG_LIB_PATH}
        optimized ${DRAFTSMAN_TINYXML2_RELEASE_LIB_PATH}
    )
ENDIF()

target_include_directories(
    DraftsmanCore
    PUBLIC
    "DraftsmanCore/Include/"
    ${DRAFTSMAN_TINYXML2_INCLUDE_PATH}
    PRIVATE
    "DraftsmanCore/Source/DraftsmanCore/"
    "DraftsmanCore/Source/DraftsmanCore/__private__/"
)

# For MSVC parse pretty filter names
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
