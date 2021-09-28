/*
 * SNUAlbedo.hpp
 *
 *  Created on: Sep 23, 2021
 *      Author: timpai
 */

#include "IAlbedo.hpp"

#ifndef SRC_INCLUDE_SNUALBEDO_HPP_
#define SRC_INCLUDE_SNUALBEDO_HPP_

namespace Model{
class SNUAlbedo : public IAlbedo {
public:
    double albedo();
};
}

#endif /* SRC_INCLUDE_SNUALBEDO_HPP_ */
