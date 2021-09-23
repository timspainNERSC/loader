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

class ModuleLoader {
public:
    virtual ~ModuleLoader();

    static ModuleLoader& getLoader()
    {
        static ModuleLoader instance; // C++11 magic static
        return instance;
    }

    enum class Module {
        iceAlbedo,
        thermodynamics
    };

    typedef boost::program_options::variables_map VariablesMap;

    void init(const VariablesMap&);
    std::set<std::string> listImplementationNames(const Module) const;
    std::set<std::string> listImplementationNames(const std::string&) const;
    std::string getInterfaceName(const Module) const;
    Module getModuleFromName(const std::string&) const;
    void setImplementation(const Module, const std::string&);
    void setImplementation(const std::string&, const std::string&);
    template<class T>
    std::unique_ptr<T> getImplementation(const Module) const;
    template<class T>
    std::unique_ptr<T> getImplementation(const std::string&) const;

    // Singleton function definitions
private:
    ModuleLoader() {};
public:
    ModuleLoader(const ModuleLoader&)   = delete;
    void operator=(const ModuleLoader&) = delete;

};

#endif /* SRC_INCLUDE_MODULELOADER_HPP */
