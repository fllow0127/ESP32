file(GLOB_RECURSE MAIN_SOURCE *.c)

idf_component_register(
    SRCS ${MAIN_SOURCE}

    INCLUDE_DIRS
    "."
)
