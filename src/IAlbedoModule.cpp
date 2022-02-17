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
template <>
std::map<std::string, std::function<std::unique_ptr<Model::IAlbedo>()>> Module<Model::IAlbedo>::functionMap = {
        {SNU_ALBEDO, newImpl<Model::IAlbedo, Model::SNUAlbedo>},
        {CCSM_ALBEDO, newImpl<Model::IAlbedo, Model::CCSMAlbedo>},
};
template <>
std::function<std::unique_ptr<Model::IAlbedo>()> Module<Model::IAlbedo>::spf = functionMap.at(SNU_ALBEDO);
template <>
std::unique_ptr<Model::IAlbedo> Module<Model::IAlbedo>::staticInstance = std::move(spf());

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
