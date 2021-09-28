set(INC "${CMAKE_CURRENT_SOURCE_DIR}/include")

find_package( PythonInterp 3 REQUIRED )

set(ModuleLoaderIncludes
    "moduleLoaderHeaders.ipp"
    "moduleLoaderFunctions.ipp"
    "moduleLoaderNames.ipp"
    "moduleLoaderAssignments.ipp"
)

add_executable(loader_ex main.cpp
include/ModuleLoader.hpp
ModuleLoader.cpp
SNUAlbedo.cpp
SNU2Albedo.cpp
CCSMAlbedo.cpp
thermoWinton.cpp
thermoIce0.cpp
${ModuleLoaderIncludes})

target_include_directories(loader_ex PRIVATE "/opt/home/include" "include")

set(ModuleLoaderFile
${CMAKE_CURRENT_SOURCE_DIR}/modules.json)

add_custom_target(
parse_modules ALL
COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/moduleloader_builder.py "--ipp" "${CMAKE_CURRENT_SOURCE_DIR}/" ${ModuleLoaderFile}
BYPRODUCTS ${ModuleLoaderIncludes}
COMMENT "Generating inclusion files for ModuleLoader.cpp"
)

add_dependencies(loader_ex parse_modules)
