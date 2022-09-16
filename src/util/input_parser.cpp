//
// Created by Pedro Soares on 9/14/22.
//

#include "input_parser.hpp"

/// Constructor, parses the input arguments and stores them in a vector of strings
InputParser::InputParser(int &argc, char **argv)
{
    for(int i = 1; i < argc; ++i) tokens.emplace_back(argv[i]);
}

/// \brief Get the value of a command line option
/// \param option FULL option to get the value of
/// \return The value of the option if it exists, otherwise an empty string
const std::string &InputParser::getCmdOption(const std::string &option) const
{
    static const std::string empty_string;

    auto itr = std::find(tokens.begin(), tokens.end(), option);
    if(itr != tokens.end() && ++itr != tokens.end()) return *itr;
    return empty_string;
}

/// \brief Check if a command line option exists
/// \param optionFull The FULL option to check for
/// \param optionSmall The SHORT option to check for (optional)
/// \return True if the option exists, otherwise false
bool InputParser::cmdOptionExists(const std::string &optionFull,
                                  const std::string &optionSmall) const
{
    bool exists = false;
    exists = std::find(tokens.begin(), tokens.end(), optionFull) != tokens.end();

    if(optionSmall.empty()) return exists;

    exists |= std::find(tokens.begin(), tokens.end(), optionSmall) != tokens.end();
    return exists;
}
