set(RAYLIB_VERSION 5.5)
include(FetchContent)

find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  if (NOT DEFINED RAYLIB_VERSION)
      set(RAYLIB_VERSION "5.5.0")
  endif()

  FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git${RAYLIB_VERSION}.tar.gz
    GIT_TAG v${RAYLIB_VERSION}
  )

  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
  endif()
endif()
