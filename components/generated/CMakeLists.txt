file(GLOB_RECURSE SOURCE *.c)

idf_component_register(
    SRCS ${SOURCE}

    INCLUDE_DIRS
    "."
    "guider_customer_fonts"
    "guider_fonts"
    "images"
    "../lvgl__lvgl/src"
)
