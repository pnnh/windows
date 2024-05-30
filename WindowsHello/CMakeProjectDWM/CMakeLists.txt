
add_executable (CMakeProjectDWM WIN32 "CMakeProjectDWM.cpp" "CMakeProjectDWM.h")

set_property(TARGET CMakeProjectDWM PROPERTY CXX_STANDARD 20)

target_compile_definitions(CMakeProjectDWM PUBLIC UNICODE _UNICODE)

target_link_libraries(CMakeProjectDWM PUBLIC dwmapi UxTheme)