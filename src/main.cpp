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

int main(int argc, char* argv[])
{
    ModuleLoader::VariablesMap map;
    if (argc > 1) {
        if (std::string(argv[1]) == "snu") {
            map["Albedo"] = "SNUAlbedo";
        } else if (std::string(argv[1]) == "ccsm"){
            map["Albedo"] = "CCSMAlbedo";
        }
    }

    ModuleLoader& loader = ModuleLoader::getLoader();
    loader.init(map);

    std::unique_ptr<IAlbedo> pAlbedo;
    pAlbedo = loader.getImplementation<IAlbedo>();
    double albedo = pAlbedo->albedo();

    std::cout << "Albedo is " << albedo << std::endl;
}
