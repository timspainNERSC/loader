/*!
 * @file IAlbedoModule.cpp
 *
 * @date Feb 16, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#include "include/IAlbedoModule.hpp"

#include <functional>
#include <list>
#include <memory>

namespace Module {
template <>
std::function<std::unique_ptr<Model::IAlbedo>()> Module<Model::IAlbedo>::spf = [](){return std::unique_ptr<Model::IAlbedo> (new Model::SNUAlbedo); };
template <>
std::unique_ptr<Model::IAlbedo> Module<Model::IAlbedo>::staticInstance = nullptr;

template <>
std::string getImplementationName<Model::SNUAlbedo>();
template <>
std::string getInterfaceName<Model::SNUAlbedo>();
template <>
std::string getImplementationName<Model::CCSMAlbedo>();
template <>
std::string getInterfaceName<Model::CCSMAlbedo>();

template <>
void Module<Model::IAlbedo>::setImplementation(const std::string& implName)
{
    if (implName == getImplementationName<Model::SNUAlbedo>()) {
        spf = []() { return std::unique_ptr<Model::IAlbedo> (new Model::SNUAlbedo); };
    } else if (implName == getImplementationName<Model::CCSMAlbedo>()) {
        spf = []() { return std::unique_ptr<Model::IAlbedo> (new Model::CCSMAlbedo); };
    } else {
        std::string what = "IAlbedoModule::setImplementation: no known implementation named " + implName;
        throw std::invalid_argument(what);
    }
    setStaticImplementation();
}

template <>
std::list<std::string> Module<Model::IAlbedo>::listImplementations()
{
    return {"SNUAlbedo", "CCSMAlbedo"};
}
template <>
std::string getImplementationName<Model::SNUAlbedo>()
{
    return "SNUAlbedo";
}

template <>
std::string getInterfaceName<Model::SNUAlbedo>()
{
    return "IAlbedo";
}

template <>
std::string getImplementationName<Model::CCSMAlbedo>()
{
    return "CCSMAlbedo";
}

template <>
std::string getInterfaceName<Model::CCSMAlbedo>()
{
    return "IAlbedo";
}

template<>
Model::IAlbedo& getImplementation<Model::IAlbedo>()
{
    return IAlbedoModule::getImplementation();
}

template <>
void setImplementation<Model::IAlbedo>(const std::string& implName)
{
    IAlbedoModule::setImplementation(implName);
}

}
