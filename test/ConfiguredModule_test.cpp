/*
 * @file ConfiguredModule_test.cpp
 *
 * @date Oct 21, 2021
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "/opt/home/include/catch2/catch.hpp"

#include "ArgV.hpp"
#include "include/Configurator.hpp"
#include "include/ModuleLoader.hpp"

TEST_CASE("Configure a module", "[Configurator, ModuleLoader]")
{
    // Create the fake command line, selecting the SNU2 albedo implementation
    ArgV argvee({"cmtest", "--Model::IAlbedo=Model::SNU2Albedo"});

    Configurator::setCommandLine(argvee.argc(), argvee());

    // ConfiguredModule::parseConfigurator();


}
