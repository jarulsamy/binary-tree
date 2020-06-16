#pragma once

#include <string>
#include <fstream>
#include <deque>

std::deque<int> load(std::string filename)
{
    std::deque<int> data;
    std::ifstream infile(filename);
    int buffer;

    while (infile >> buffer)
        data.push_back(buffer);

    return data;
}
