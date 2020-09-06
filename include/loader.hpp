#pragma once

#include <string>
#include <fstream>
#include <deque>

#include <stdexcept>

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
