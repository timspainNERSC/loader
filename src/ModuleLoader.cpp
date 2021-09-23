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

    m_modules = {
            {"Albedo", Module::iceAlbedo},
            {"thermodynamics", Module::thermodynamics}
    };

    m_availableImplementationNames = {
            {
                    Module::iceAlbedo, {
                    "SNUAlbedo",
                    "SNU2Albedo",
                    "CCSMAlbedo"
                    }
            },{
                    Module::thermodynamics, {
                            "thermoWinton",
                            "thermoIce0"
                    }
            }
    };

    m_namedImplementations = {
            {"SNUAlbedo", Implementation::SNUAlbedo},
            {"SNU2Albedo", Implementation::SNU2Albedo},
            {"CCSMAlbedo", Implementation::CCSMAlbedo},
            {"thermoWinton", Implementation::thermoWinton},
            {"thermoIce0", Implementation::thermoIce0}
    };

    // Load default implementations
    m_implementations[Module::iceAlbedo] = Implementation::SNUAlbedo;
    m_implementations[Module::thermodynamics] = Implementation::thermoIce0;

    // Load the named implementations from the provided map
    for (auto const& i : map) {
        m_implementations[m_modules[i.first]] = m_namedImplementations[i.second];
    }
}

template<>
std::unique_ptr<IAlbedo> ModuleLoader::getImplementation() const
{
    Implementation impl = m_implementations.at(Module::iceAlbedo);
    switch(impl) {
    case(Implementation::SNUAlbedo):
            return std::unique_ptr<SNUAlbedo>(new SNUAlbedo);
    case(Implementation::CCSMAlbedo):
            return std::unique_ptr<CCSMAlbedo>(new CCSMAlbedo);
    default:
        return nullptr;
    }
}
