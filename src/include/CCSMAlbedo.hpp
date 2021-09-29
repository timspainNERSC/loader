/*
 * CCSMAlbedo.hpp
 *
 *  Created on: Sep 23, 2021
 *      Author: timpai
 */

#include "IAlbedo.hpp"

#ifndef SRC_INCLUDE_CCSMALBEDO_HPP_
#define SRC_INCLUDE_CCSMALBEDO_HPP_

namespace Model {
class CCSMAlbedo : public IAlbedo {
public:
    double albedo();
};
}

#endif /* SRC_INCLUDE_CCSMALBEDO_HPP_ */
