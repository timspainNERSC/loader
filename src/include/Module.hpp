/*!
 * @file Module.hpp
 *
 * @date Feb 14, 2022
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#ifndef SRC_MODULE_HPP
#define SRC_MODULE_HPP

#include <list>
#include <string>
#include <memory>

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
    static void setImplementation(const std::string& implName);

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
    static void setStaticImplementation() {
        staticInstance = std::move(spf());
    }

    static std::function<std::unique_ptr<I>()> spf;
    static std::unique_ptr<I> staticInstance;
};

template <typename I>
std::function<std::unique_ptr<I>()> Module<I>::spf;
template <typename I>
std::unique_ptr<I> Module<I>::staticInstance;
}
#endif /* SRC_MODULE_HPP */
