/*!
 * @file Module.hpp
 *
 * @date Feb 14, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#ifndef SRC_MODULE_HPP
#define SRC_MODULE_HPP

#include <functional>
#include <list>
#include <map>
#include <memory>
#include <string>

namespace Module {

template <typename I>
std::string getImplementationName();

template <typename I>
std::string getInterfaceName();

template <typename I>
I& getImplementation();

template <typename I>
void setImplementation(const std::string&);

template <typename I>
class Module {
public:
    static void setImplementation(const std::string& implName)
    {
        spf = functionMap.at(implName);
        staticInstance = std::move(spf());
    }

    static std::unique_ptr<I> getInstance()
    {
        return spf();
    }

    static I& getImplementation()
    {
        return *staticInstance;
    }

    static std::list<std::string> listImplementations();

private:
    static std::function<std::unique_ptr<I>()> spf;
    static std::unique_ptr<I> staticInstance;
    static std::map<std::string, std::function<std::unique_ptr<I>()>> functionMap;

};

template <typename I>
std::function<std::unique_ptr<I>()> Module<I>::spf;
template <typename I>
std::unique_ptr<I> Module<I>::staticInstance;
template <typename I>
std::map<std::string, std::function<std::unique_ptr<I>()>> Module<I>::functionMap;
}
#endif /* SRC_MODULE_HPP */
