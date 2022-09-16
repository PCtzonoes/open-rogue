//
// Created by Pedro Soares on 9/14/22.
//

#pragma once

#include <algorithm>
#include <string>
#include <vector>

/// \brief Class to parse command line arguments
class InputParser
{
    std::vector<std::string> tokens{};

public:
    InputParser(int &argc, char **argv);

    [[nodiscard]] const std::string &getCmdOption(const std::string &option) const;

    [[nodiscard]] bool cmdOptionExists(const std::string &optionFull,
                                       const std::string &optionSmall = "") const;
};
