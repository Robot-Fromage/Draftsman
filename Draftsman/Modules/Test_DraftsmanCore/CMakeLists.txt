cmake_minimum_required( VERSION 3.13.2 )

file(
    GLOB_RECURSE
    source_list
    RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "Test_DraftsmanCore/Include/*"
    "Test_DraftsmanCore/Source/*"
)

add_executable( Test_DraftsmanCore ${source_list} )

target_link_libraries( Test_DraftsmanCore DraftsmanCore )

target_include_directories(
    Test_DraftsmanCore
    PUBLIC
    "Test_DraftsmanCore/Include/"
    PRIVATE
    "Test_DraftsmanCore/Source/"
)

# For MSVC parse pretty filter names
foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
