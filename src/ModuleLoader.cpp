/*
 * @file ModuleLoader.cpp
 *
 * @date Sep 23, 2021
 * @author Tim Spain
 */

#include "include/ModuleLoader.hpp"
#include <memory>

#include "include/IAlbedo.hpp"
#include "include/SNUAlbedo.hpp"
#include "include/CCSMAlbedo.hpp"

void ModuleLoader::init(const VariablesMap& map)
{
    // Initialise the available modules. This is currently hardcoded at compile time.
    // TODO: Use CMake etc. to create a system that is dynamically built at compile time.

    m_availableImplementationNames = {
            {
                    "Albedo", {
                    "SNUAlbedo",
                    "SNU2Albedo",
                    "CCSMAlbedo"
                    }
            },{
                    "thermodynamics", {
                            "thermoWinton",
                            "thermoIce0"
                    }
            }
    };

    // Set of all defined interfaces
    for (const auto& element: m_availableImplementationNames) {
        m_modules.insert(element.first);
    }

    // Load default implementations
    m_implementations["Albedo"] = "SNUAlbedo";
    m_implementations["thermodynamics"] = "thermoIce0";

    // Load the named implementations from the provided map
    for (auto const& i : map) {
        std::string module = i.first;
        if (m_modules.count(module) < 1) {
            // Default to ignoring unknown modules
            continue;
        }
        if (m_availableImplementationNames[module].count(i.second) < 1) {
            std::string what = "ModuleLoader::init(): Module ";
            what += module + " does not have an implementation named " + i.second;
            throw std::invalid_argument(what);
        }
        m_implementations[i.first] = i.second;
    }
}

template<>
std::unique_ptr<IAlbedo> ModuleLoader::getImplementation() const
{
    std::string impl = m_implementations.at("Albedo");
    if (impl == "SNUAlbedo")
            return std::unique_ptr<SNUAlbedo>(new SNUAlbedo);
    else if (impl == "CCSMAlbedo")
            return std::unique_ptr<CCSMAlbedo>(new CCSMAlbedo);
    // m_implementations should only have valid values due to the check when loading the names into
    // the map
    else
        return nullptr;
}
