set(INC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(loader_ex main.cpp
include/ModuleLoader.hpp
ModuleLoader.cpp
SNUAlbedo.cpp
CCSMAlbedo.cpp)

target_include_directories(loader_ex PRIVATE "/opt/home/include" "include")
