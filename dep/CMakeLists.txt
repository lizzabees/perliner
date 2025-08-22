add_library(raygui STATIC)
target_include_directories(raygui PUBLIC dep)
target_link_libraries(raygui raylib)
target_sources(raygui PUBLIC raygui.h PRIVATE raygui.c)
set_target_properties(
  raygui PROPERTIES
         C_STANDARD 23
         C_EXTENSIONS OFF
)

