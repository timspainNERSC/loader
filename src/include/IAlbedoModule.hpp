/*!
 * @file IAlbedoModule.hpp
 *
 * @date Feb 15, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#ifndef SRC_INCLUDE_IALBEDOMODULE_HPP
#define SRC_INCLUDE_IALBEDOMODULE_HPP

#include "include/IAlbedo.hpp"
#include "include/SNUAlbedo.hpp"
#include "include/CCSMAlbedo.hpp"

#include "include/Module.hpp"

#include <functional>
#include <list>
#include <memory>
#include <string>

namespace Module {
template <>
std::string getImplementationName<Model::SNUAlbedo>();
template <>
std::string getInterfaceName<Model::SNUAlbedo>();
template <>
std::string getImplementationName<Model::CCSMAlbedo>();
template <>
std::string getInterfaceName<Model::CCSMAlbedo>();


class IAlbedoModule {
public:

    static void setImplementation(const std::string& implName)
    {
        if (implName == getImplementationName<Model::SNUAlbedo>()) {
            spf = []() { return std::unique_ptr<Model::IAlbedo> (new Model::SNUAlbedo); };
        } else if (implName == getImplementationName<Model::CCSMAlbedo>()) {
            spf = []() { return std::unique_ptr<Model::IAlbedo> (new Model::CCSMAlbedo); };
        } else {
            std::string what = "IAlbedoModule::setImplementation: no known implementation named " + implName;
            throw std::invalid_argument(what);
        }
    }
    static std::unique_ptr<Model::IAlbedo> getInstance()
    {
        return spf();
    }
    static std::unique_ptr<Model::IAlbedo> getImplementation()
    {
        return spf();
    }
    static std::list<std::string> listImplementations()
    {
        return { "SNUAlbedo", "CCSMAlbedo" };
    }

private:
    static std::function<std::unique_ptr<Model::IAlbedo>()> spf;
};


}

#endif /* SRC_INCLUDE_IALBEDOMODULE_HPP */
