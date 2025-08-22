include(FetchContent)

find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    if (NOT DEFINED RAYLIB_CPP_VERSION)
        set(RAYLIB_CPP_VERSION "5.5.0")
    endif()

    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v${RAYLIB_CPP_VERSION}
    )

    if (NOT raylib_cpp_POPULATED) # Have we downloaded raylib yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_MakeAvailable(raylib_cpp)
    endif() 
endif()
