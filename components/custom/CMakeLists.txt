file(GLOB_RECURSE CUSTOM_SOURCE *.c)

idf_component_register(
    SRCS ${CUSTOM_SOURCE}

    INCLUDE_DIRS
    "."
    "../lvgl__lvgl/src"
)
