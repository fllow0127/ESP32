cmake_minimum_required(VERSION 3.12.4)

set(LVGL_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

# if(ESP_PLATFORM)
# include(${CMAKE_CURRENT_LIST_DIR}/env_support/cmake/esp.cmake)
# else()
# include(${CMAKE_CURRENT_LIST_DIR}/env_support/cmake/custom.cmake)
# endif()
file(GLOB_RECURSE LVGL_SOURCE *.c)
idf_component_register(
    SRCS ${LVGL_SOURCE}

    INCLUDE_DIRS
    "."
    "src"
    "src/core"
    "src/draw"
    "src/font"
    "src/hal"
    "src/misc"
    "src/widgets"
    "src/extra"
    "src/extra/layouts"
    "src/extra/layouts/flex"
    "src/extra/layouts/grid"
    "src/extra/themes"
    "src/extra/themes/basic"
    "src/extra/themes/default"
    "src/extra/widgets/calendar"
    "src/extra/widgets/colorwheel"
    "src/extra/widgets"
    "src/extra/widgets/imgbtn"
    "src/extra/widgets/keyboard"
    "src/extra/widgets/led"
    "src/extra/widgets/list"
    "src/extra/widgets/msgbox"
    "src/extra/widgets/spinbox"
    "src/extra/widgets/spinner"
    "src/extra/widgets/tabview"
    "src/extra/widgets/tileview"
    "src/extra/widgets/win"
    "src/extra/widgets/carousel"
    "src/extra/widgets/dclock"
)