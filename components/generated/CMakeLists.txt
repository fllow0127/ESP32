file(GLOB_RECURSE GENERATED_SOURCE *.c)

idf_component_register(
    SRCS ${GENERATED_SOURCE}

    INCLUDE_DIRS
    "."
    "guider_customer_fonts"
    "guider_fonts"
    "images"
    "../lvgl__lvgl/src"
)
