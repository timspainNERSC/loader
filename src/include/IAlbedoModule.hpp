/*!
 * @file IAlbedoModule.hpp
 *
 * @date Feb 15, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#ifndef SRC_INCLUDE_IALBEDOMODULE_HPP
#define SRC_INCLUDE_IALBEDOMODULE_HPP

#include "include/IAlbedo.hpp"

#include "include/Module.hpp"

namespace Module {

static const std::string SNU_ALBEDO = "SNUAlbedo";
static const std::string CCSM_ALBEDO = "CCSMAlbedo";

class IAlbedoModule : public Module<Model::IAlbedo>
{
};

}

#endif /* SRC_INCLUDE_IALBEDOMODULE_HPP */
