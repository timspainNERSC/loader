/*
 * Ithermodynamics.hpp
 *
 *  Created on: Sep 24, 2021
 *      Author: timpai
 */

#include <string>

#ifndef SRC_INCLUDE_ITHERMODYNAMICS_HPP_
#define SRC_INCLUDE_ITHERMODYNAMICS_HPP_

namespace Model {
class Ithermodynamics {
public:
    virtual ~Ithermodynamics() = default;
    virtual std::string name() const = 0;
};
}
#endif /* SRC_INCLUDE_ITHERMODYNAMICS_HPP_ */
