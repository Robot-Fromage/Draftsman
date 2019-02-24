cmake_minimum_required( VERSION 3.13.2 )

file(
    GLOB_RECURSE
    source_list
    RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "Test_DraftsmanGUI/Include/*"
    "Test_DraftsmanGUI/Source/*"
)

add_executable( Test_DraftsmanGUI ${source_list} )

target_link_libraries( Test_DraftsmanGUI DraftsmanGUI )

set_target_properties( Test_DraftsmanGUI PROPERTIES CMAKE_AUTOMOC ON )

target_include_directories(
    Test_DraftsmanGUI
    PUBLIC
    "Test_DraftsmanGUI/Include/"
    PRIVATE
    "Test_DraftsmanGUI/Source/"
)

# For MSVC parse pretty filter names
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
