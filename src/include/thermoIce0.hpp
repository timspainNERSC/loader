/*
 * thermoIce0.hpp
 *
 *  Created on: Sep 24, 2021
 *      Author: timpai
 */

#ifndef SRC_INCLUDE_THERMOICE0_HPP_
#define SRC_INCLUDE_THERMOICE0_HPP_

#include "Ithermodynamics.hpp"

namespace ModelDG {
class thermoIce0: public Model::Ithermodynamics {
public:
    std::string name() const;
private:
    std::string realName() const;
};
}

#endif /* SRC_INCLUDE_THERMOICE0_HPP_ */
