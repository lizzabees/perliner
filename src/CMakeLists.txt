add_executable(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC inc)
target_link_libraries(${PROJECT_NAME} raylib raylib_cpp raygui)

target_sources(${PROJECT_NAME}
  PUBLIC
    FILE_SET HEADERS BASE_DIRS ${PROJECT_SOURCE_DIR}/inc FILES 
      ../inc/clamp.hpp
      ../inc/noise2d.hpp
      ../inc/perlin.hpp

  PRIVATE
    clamp.cpp
    main.cpp
    perlin.cpp
)

set_target_properties(
  ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS OFF
)

# Web Configurations
# if (${PLATFORM} STREQUAL "Web")
#     set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html") # Tell Emscripten to build an example.html file.
#     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
# endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
