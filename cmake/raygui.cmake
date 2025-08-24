include(FetchContent)

find_package(raygui QUIET)
if (NOT raygui_FOUND)
    if (NOT DEFINED raygui_VERSION)
        set(raygui_VERSION "4.0")
    endif()

    FetchContent_Declare(
        raygui
        GIT_REPOSITORY https://github.com/raysan5/raygui
        GIT_TAG ${raygui_VERSION}
        SOURCE_SUBDIR projects/CMake
    )

    if (NOT raygui_POPULATED) # Have we downloaded raylib yet?
      set(FETCHCONTENT_QUIET NO)
      FetchContent_MakeAvailable(raygui)
    endif() 
endif()
