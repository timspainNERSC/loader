/*
 * @file ModuleLoader.hpp
 *
 * @date Sep 23, 2021
 * @author Tim Spain
 */

#ifndef SRC_INCLUDE_MODULELOADER_HPP
#define SRC_INCLUDE_MODULELOADER_HPP

#include <memory>
#include <string>
#include <set>
#include <boost/program_options.hpp>
/*
class IAlbedo;
class SNUAlbedo;
class SNU2Albedo;
class CCSMAlbedo;
*/
class ModuleLoader {
public:
    static ModuleLoader& getLoader()
    {
        static ModuleLoader instance; // C++11 magic static
        return instance;
    }

    enum class Module {
        iceAlbedo,
        thermodynamics
    };

    // List of all possible implementations of any of the Modules
    enum class Implementation {
        SNUAlbedo,
        SNU2Albedo,
        CCSMAlbedo,
        thermoWinton,
        thermoIce0
    };

    //typedef boost::program_options::variables_map VariablesMap;
    typedef std::map<std::string, std::string> VariablesMap;

    void init(const VariablesMap&);
    std::set<std::string> listImplementationNames(const Module) const;
    std::set<std::string> listImplementationNames(const std::string&) const;
    std::string getInterfaceName(const Module) const;
    Module getModuleFromName(const std::string&) const;
    void setImplementation(const Module, const std::string&);
    void setImplementation(const std::string&, const std::string&);
    template<class T>
    std::unique_ptr<T> getImplementation() const;
    // Explicit specializations for the interface classes

    // Singleton function definitions
private:
    ModuleLoader() {};
public:
    ModuleLoader(const ModuleLoader&)   = delete;
    void operator=(const ModuleLoader&) = delete;

private:
    // One module could have many names (but probably shouldn't)
    std::map<std::string, Module> m_modules;
    // Names of all available implmentations
    std::map<std::string, Implementation> m_namedImplementations;
    // Names of implementations
    std::map<Module, std::set<std::string>> m_availableImplementationNames;
    // Enums of the selected implementations for each module
    std::map<Module, Implementation> m_implementations;
};

#endif /* SRC_INCLUDE_MODULELOADER_HPP */
