/*
 * IAlbedo.hpp
 *
 *  Created on: Sep 23, 2021
 *      Author: timpai
 */

#ifndef SRC_INCLUDE_IALBEDO_HPP_
#define SRC_INCLUDE_IALBEDO_HPP_

class IAlbedo {
public:
    virtual ~IAlbedo() = default;
    virtual double albedo() = 0;
};

#endif /* SRC_INCLUDE_IALBEDO_HPP_ */
