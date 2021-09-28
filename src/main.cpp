/**
 * @file main.cpp
 *
 * @date Sep 23, 2021
 * @author Tim Spain
 */

#include <string>
#include <map>
#include <memory>
#include <iostream>

#include "include/ModuleLoader.hpp"
#include "include/IAlbedo.hpp"
#include "include/Ithermodynamics.hpp"

int main(int argc, char* argv[])
{
    ModuleLoader::VariablesMap map;
    if (argc > 1) {
        if (std::string(argv[1]) == "snu") {
            map["Model::Albedo"] = "Model::SNUAlbedo";
        } else if (std::string(argv[1]) == "snu2") {
            map["Model::Albedo"] = "SNU2::SNU2Albedo";
        } else if (std::string(argv[1]) == "ccsm"){
            map["Model::Albedo"] = "Model::CCSMAlbedo";
        } else if (std::string(argv[1]) == "ukmoum"){
            map["Model::Albedo"] = "UM::UMAlbedo";
        }
    }
    if (argc > 2) {
        if (std::string(argv[2]) == "winton") {
            map["Model::thermodynamics"] = "Model::thermoWinton";
        } else if (std::string(argv[2]) == "ice0"){
            map["Model::thermodynamics"] = "ModelDG::thermoIce0";
        }
    }

    ModuleLoader& loader = ModuleLoader::getLoader();
    loader.init(map);

    std::cout << "Available modules are:" << std::endl;
    for ( auto mm : loader.listModules()) {
        std::cout << "    " << mm << std::endl;
    }

    std::string firstModule = *loader.listModules().begin();
    std::cout << "Available implementations for module " << firstModule << " are:" << std::endl;
    for (auto ii : loader.listImplementations(firstModule)) {
        std::cout << "    " << ii << std::endl;
    }

    std::unique_ptr<Model::IAlbedo> pAlbedo;
    pAlbedo = loader.getImplementation<Model::IAlbedo>();
    double albedo = pAlbedo->albedo();

    std::cout << "Albedo is " << albedo << std::endl;

    std::unique_ptr<Model::Ithermodynamics> pthermo = loader.getImplementation<Model::Ithermodynamics>();

    std::cout << "Thermodynamics routine is named " << pthermo->name() << std::endl;
}
