/*
 * @file ModuleLoader.cpp
 *
 * @date Sep 23, 2021
 */

#include "include/ModuleLoader.hpp"
#include <stdexcept>
#include <memory>

#include "moduleLoaderHeaders.ipp"

// Pointers to functions returning new instances implementing the interfaces
// &
// Functions creating a new instance of each implementation, and returning it
// as a pointer to its interface class

#include "moduleLoaderFunctions.ipp"

void throwup(const std::string& module, const std::string& impl)
{
    std::string what = "ModuleLoader::init(): Module ";
    what += module + " does not have an implementation named " + impl;
    throw std::invalid_argument(what);
}

void ModuleLoader::init(const VariablesMap& map)
{
    // Initialise the available modules.
    // This is currently hardcoded at compile time.
    // TODO: Use CMake etc. to create a system that dynamically creates this
    //       file at compile time.

#include "moduleLoaderNames.ipp"

    // Set of all defined interfaces
    for (const auto& element: m_availableImplementationNames) {
        m_modules.insert(element.first);
    }

    // Load the named implementations from the provided map
    for (auto const& i : map) {
        std::string module = i.first;
        std::string impl = i.second;

#include "moduleLoaderAssignments.ipp"
    }
}

