/*
 * @file ModuleLoader.hpp
 *
 * @date Sep 23, 2021
 */

#ifndef SRC_INCLUDE_MODULELOADER_HPP
#define SRC_INCLUDE_MODULELOADER_HPP

#include <memory>
#include <string>
#include <set>
#include <map>

class ModuleLoader {
public:
    static ModuleLoader& getLoader()
    {
        static ModuleLoader instance; // C++11 magic static
        return instance;
    }

    typedef std::map<std::string, std::string> VariablesMap;

    void init(const VariablesMap&);
    inline const std::set<std::string>& listModules() const
    {
        return m_modules;
    }
    inline const std::set<std::string>& listImplementations(const std::string& module) const
    {
        return m_availableImplementationNames.at(module);
    }
    template<class T>
    std::unique_ptr<T> getImplementation() const;

    // Singleton function definitions
private:
    ModuleLoader() {};
public:
    ModuleLoader(const ModuleLoader&)   = delete;
    void operator=(const ModuleLoader&) = delete;

private:
    // One module could have many names (but probably shouldn't)
    std::set<std::string> m_modules;
    // Names of available implementations
    std::map<std::string, std::set<std::string>> m_availableImplementationNames;
};

#endif /* SRC_INCLUDE_MODULELOADER_HPP */
