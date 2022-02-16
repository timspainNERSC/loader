/*!
 * @file Module.hpp
 *
 * @date Feb 14, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#ifndef SRC_MODULE_HPP
#define SRC_MODULE_HPP

#include <list>
#include <map>
#include <set>
#include <string>
#include <memory>

namespace Module {

template <typename I>
std::string getImplementationName();

template <typename I>
std::string getInterfaceName();

template <typename I>
std::unique_ptr<I> getImplementation();

template <typename I>
void setImplementation(const std::string&);

}
#endif /* SRC_MODULE_HPP */
