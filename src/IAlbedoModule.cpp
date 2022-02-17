/*!
 * @file IAlbedoModule.cpp
 *
 * @date Feb 16, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#include "include/IAlbedoModule.hpp"

#include "include/CCSMAlbedo.hpp"
#include "include/SNUAlbedo.hpp"

namespace Module {
const std::string IAlbedoModule::SNU_ALBEDO = "SNUAlbedo";
const std::string IAlbedoModule::CCSM_ALBEDO = "CCSMAlbedo";

template <>
Module<Model::IAlbedo>::map Module<Model::IAlbedo>::functionMap = {
        {IAlbedoModule::SNU_ALBEDO, newImpl<Model::IAlbedo, Model::SNUAlbedo>},
        {IAlbedoModule::CCSM_ALBEDO, newImpl<Model::IAlbedo, Model::CCSMAlbedo>},
};
template <>
Module<Model::IAlbedo>::fn Module<Model::IAlbedo>::spf = functionMap.at(IAlbedoModule::SNU_ALBEDO);
template <>
std::unique_ptr<Model::IAlbedo> Module<Model::IAlbedo>::staticInstance = std::move(spf());

template<>
std::string Module<Model::IAlbedo>::moduleName()
{
    return "IAlbedo";
}

template<>
Model::IAlbedo& getImplementation<Model::IAlbedo>()
{
    return getImplTemplate<Model::IAlbedo, IAlbedoModule>();
}

template <>
void setImplementation<Model::IAlbedo>(const std::string& implName)
{
    setImplTemplate<IAlbedoModule>(implName);
}

}
