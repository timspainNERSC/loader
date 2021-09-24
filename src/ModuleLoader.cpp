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
#include "include/SNU2Albedo.hpp"
#include "include/CCSMAlbedo.hpp"

#include "include/Ithermodynamics.hpp"
#include "include/thermoWinton.hpp"
#include "include/thermoIce0.hpp"

// Pointers to functions returning new instances implementing the interfaces
std::unique_ptr<IAlbedo> (*AlbedoImpl)();
std::unique_ptr<Ithermodynamics> (*thermodynamicsImpl)();

// Functions creating a new instance of each implementation, and returning it
// as a pointer to its interface class
// Albedo
std::unique_ptr<IAlbedo> newSNUAlbedo()
{
    return std::unique_ptr<SNUAlbedo>(new SNUAlbedo);
}
std::unique_ptr<IAlbedo> newSNU2Albedo()
{
    return std::unique_ptr<SNU2Albedo>(new SNU2Albedo);
}
std::unique_ptr<IAlbedo> newCCSMAlbedo()
{
    return std::unique_ptr<CCSMAlbedo>(new CCSMAlbedo);
}
// thermodynamics
std::unique_ptr<Ithermodynamics> newthermoWinton()
{
return std::unique_ptr<thermoWinton>(new thermoWinton);
}
std::unique_ptr<Ithermodynamics> newthermoIce0()
{
return std::unique_ptr<thermoIce0>(new thermoIce0);
}

void throwup(const std::string& module, const std::string& impl)
{
    std::string what = "ModuleLoader::init(): Module ";
    what += module + " does not have an implementation named " + impl;
    throw std::invalid_argument(what);
}

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

    // Load the named implementations from the provided map
    for (auto const& i : map) {
        std::string module = i.first;
        std::string impl = i.second;

        if (module == "Albedo") {
            if (impl == "SNUAlbedo") {
                AlbedoImpl = &newSNUAlbedo;
            } else if (impl == "SNU2Albedo") {
                AlbedoImpl = &newSNU2Albedo;
            } else if (impl == "CCSMAlbedo") {
                AlbedoImpl = &newCCSMAlbedo;
            } else {
                throwup(module, impl);
            }

        } else if (module == "thermodynamics") {
            if (impl == "thermoWinton") {
                thermodynamicsImpl = &newthermoWinton;
            } else if (impl == "thermoIce0") {
                thermodynamicsImpl = &newthermoIce0;
            } else {
                throwup(module, impl);
            }
        }
    }
}

template<>
std::unique_ptr<IAlbedo> ModuleLoader::getImplementation() const
{
    return (*AlbedoImpl)();
}
template<>
std::unique_ptr<Ithermodynamics> ModuleLoader::getImplementation() const
{
    return (*thermodynamicsImpl)();
}
