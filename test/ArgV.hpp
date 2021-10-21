/*!
 * @file ArgV.hpp
 *
 * @date Oct 11, 2021
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#include <vector>
#include <string>

#ifndef TEST_ARGV_HPP
#define TEST_ARGV_HPP

// A class to work around the limitations on casting string literals to char*.
class ArgV {
public:
    ArgV(std::vector<std::string> vs);
    ~ArgV();

    char** operator()();
    int argc();

private:
    int nStrings;
    char** ppc;
};

#endif /* TEST_ARGV_HPP */
