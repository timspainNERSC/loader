/*!
 * @file IAlbedoModule.cpp
 *
 * @date Feb 16, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#include "include/IAlbedoModule.hpp"

namespace Module {
std::function<std::unique_ptr<Model::IAlbedo>()> Module::IAlbedoModule::spf;

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
std::unique_ptr<Model::IAlbedo> getImplementation<Model::IAlbedo>()
{
    return IAlbedoModule::getImplementation();
}

template <>
void setImplementation<Model::IAlbedo>(const std::string& implName)
{
    IAlbedoModule::setImplementation(implName);
}

}
