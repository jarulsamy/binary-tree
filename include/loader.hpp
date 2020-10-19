#ifndef LOADER_HPP
#define LOADER_HPP

#include <deque>
#include <fstream>
#include <stdexcept>
#include <string>

#include "btree.hpp"

/**
 * @brief Load a txt file of newline seperated ints into a BTree.
 *
 * @throw std::runtime_error("Error opening file")
 * @param filename Name of txt file to open
 * @return BTree<int>
 */
BTree<int> load(const std::string &filename) {
    BTree<int> data;
    std::ifstream infile(filename);

    if (!infile.good()) throw std::runtime_error("Error opening file");

    int buffer;

    while (infile >> buffer) data.insert(buffer);

    return data;
}
#endif
