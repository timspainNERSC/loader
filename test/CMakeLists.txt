# Build the unit test

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../src")
set(INCLUDE_DIR "${SRC_DIR}/include")
set(IPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ModuleLoaderTestModules")

add_executable(testModuleLoader
    "moduleLoader_test.cpp"
    "${SRC_DIR}/ModuleLoader.cpp"
)
target_include_directories(testModuleLoader PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" "${INCLUDE_DIR}" "${IPP_DIR}")
target_link_libraries(testModuleLoader PRIVATE Catch2::Catch2)

add_executable(testConfiguredModule
    "ConfiguredModule_test.cpp"
    "ArgV.cpp"
    "${SRC_DIR}/ModuleLoader.cpp"
    "${SRC_DIR}/Configurator.cpp"
    "${SRC_DIR}/ConfiguredModule.cpp"
)
target_include_directories(testConfiguredModule PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" "${INCLUDE_DIR}" "${IPP_DIR}" ${Boost_INCLUDE_DIRS})
target_link_libraries(testConfiguredModule PRIVATE Catch2::Catch2 ${Boost_LIBRARIES})
