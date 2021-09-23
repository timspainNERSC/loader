set(INC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(loader include/ModuleLoader.hpp ModuleLoader.cpp)

target_include_directories(loader PRIVATE "/opt/home/include" "include")
