
add_executable (CMakeProjectHello WIN32 "CMakeProjectHello.cpp" "CMakeProjectHello.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProjectHello PROPERTY CXX_STANDARD 20)
endif()
