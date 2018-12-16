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

target_link_libraries( DraftsmanGUI DraftsmanCore )

find_package(
    Qt5
    REQUIRED COMPONENTS
    Core
    Widgets
    Gui
)

target_link_libraries(
    DraftsmanGUI
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)

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
