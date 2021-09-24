/*
 * @file ModuleLoader.cpp
 *
 * @date Sep 23, 2021
 */

#include "include/ModuleLoader.hpp"
#include <stdexcept>
/*
#include "include/I1.hpp"
#include "include/Impl11.hpp"
#include "include/Impl12.hpp"

#include "include/I2.hpp"
#include "include/Impl21.hpp"
#include "include/Impl22.hpp"
*/
// The following classes would normally be declared in the above header files
// and defined in the corresponding source files.
class I1 {};
class Impl11 : public I1 {};
class Impl12 : public I1 {};

class I2 {};
class Impl21 : public I2 {};
class Impl22 : public I2 {};

// Pointers to functions returning new instances implementing the interfaces
std::unique_ptr<I1> (*Impl1)();
std::unique_ptr<I2> (*Impl2)();

// Functions creating a new instance of each implementation, and returning it
// as a pointer to its interface class
// Interface1
std::unique_ptr<I1> newImpl11()
{
    return std::unique_ptr<Impl11>(new Impl11);
}
std::unique_ptr<I1> newImpl12()
{
    return std::unique_ptr<Impl12>(new Impl12);
}
// Interface2
std::unique_ptr<I2> newImpl21()
{
return std::unique_ptr<Impl21>(new Impl21);
}
std::unique_ptr<I2> newImpl22()
{
return std::unique_ptr<Impl22>(new Impl22);
}

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

    m_availableImplementationNames = {
            {
                    "Interface1", {
                            "Impl11",
                            "Impl12"
                    }
            },{
                    "Interface2", {
                            "Impl21",
                            "Impl22"
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

        if (module == "Interface1") {
            if (impl == "Impl11") {
                Impl1 = &newImpl11;
            } else if (impl == "Impl12") {
                Impl1 = &newImpl12;
            } else {
                throwup(module, impl);
            }

        } else if (module == "Interface2") {
            if (impl == "Impl21") {
                Impl2 = &newImpl21;
            } else if (impl == "Impl22") {
                Impl2 = &newImpl22;
            } else {
                throwup(module, impl);
            }
        }
    }
}

template<>
std::unique_ptr<I1> ModuleLoader::getImplementation() const
{
    return (*Impl1)();
}
template<>
std::unique_ptr<I2> ModuleLoader::getImplementation() const
{
    return (*Impl2)();
}
