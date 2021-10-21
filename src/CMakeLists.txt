set(INC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(loader_ex main.cpp
include/ModuleLoader.hpp
ModuleLoader.cpp
SNUAlbedo.cpp
SNU2Albedo.cpp
CCSMAlbedo.cpp
thermoWinton.cpp
thermoIce0.cpp
)

target_include_directories(loader_ex PRIVATE "/opt/home/include" "include" "modules" "${CMAKE_CURRENT_SOURCE_DIR}")

# Build the module loader files. Defines the 'parse_modules' target
set(ModuleLoaderIppTargetDirectory
"${CMAKE_CURRENT_SOURCE_DIR}/modules/")
add_subdirectory(modules)

add_dependencies(loader_ex parse_modules)
