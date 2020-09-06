#ifndef LOADER_HPP
#define LOADER_HPP
#include <string>
#include <fstream>
#include <deque>

#include <stdexcept>

/**
 * @brief Load a txt file of newline seperated ints into a deque.
 *
 * @throw std::runtime_error("Error opening file")
 * @param filename Name of txt file to open
 * @return std::deque<int>
 */
std::deque<int> load(const std::string &filename)
{
    std::deque<int> data;
    std::ifstream infile(filename);

    if (!infile.good())
        throw std::runtime_error("Error opening file");

    int buffer;

    while (infile >> buffer)
        data.push_back(buffer);

    return data;
}
#endif
