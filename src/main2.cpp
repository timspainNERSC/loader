/*!
 * @file main2.cpp
 *
 * @date Feb 14, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */


#include "include/IAlbedo.hpp"
#include "include/SNUAlbedo.hpp"
#include "include/IAlbedoModule.hpp"

#include <iostream>

namespace Model {
void doIt()
{
    Module::setImplementation<IAlbedo>("SNUAlbedo");
    std::cout << Module::getImplementation<IAlbedo>().albedo() << std::endl;

    Module::setImplementation<IAlbedo>("CCSMAlbedo");
    std::cout << Module::getImplementation<IAlbedo>().albedo() << std::endl;
}
}

int main()
{

    Model::doIt();
}

