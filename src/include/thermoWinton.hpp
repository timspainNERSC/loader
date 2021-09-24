/*
 * thermoWinton.hpp
 *
 *  Created on: Sep 24, 2021
 *      Author: timpai
 */

#ifndef SRC_INCLUDE_THERMOWINTON_HPP_
#define SRC_INCLUDE_THERMOWINTON_HPP_

#include "Ithermodynamics.hpp"

class thermoWinton: public Ithermodynamics {
public:
    std::string name() const;
};

#endif /* SRC_INCLUDE_THERMOWINTON_HPP_ */
