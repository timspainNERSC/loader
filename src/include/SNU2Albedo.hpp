/*
 * SNU2Albedo.hpp
 *
 *  Created on: Sep 23, 2021
 *      Author: timpai
 */

#include "IAlbedo.hpp"

#ifndef SRC_INCLUDE_SNU2ALBEDO_HPP_
#define SRC_INCLUDE_SNU2ALBEDO_HPP_

namespace SNU2 {
class SNU2Albedo : public Model::IAlbedo {
public:
    double albedo();
};
}

#endif /* SRC_INCLUDE_SNU2ALBEDO_HPP_ */
