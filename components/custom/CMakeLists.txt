file(GLOB_RECURSE SOURCE *.c)

idf_component_register(
    SRCS ${SOURCE}

    INCLUDE_DIRS
    "."
    "../lvgl__lvgl/src"
)
