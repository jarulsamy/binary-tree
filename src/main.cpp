#include <iostream>
#include <deque>
#include <string>

#include "btree.hpp"
#include "loader.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btree.o FILENAME.txt" << std::endl;
        return -1;
    }

    std::deque<int> data = load(argv[1]);

    BTree<int> btree;
    int buffer;

    for (int i : data)
        btree.insert(i);

    std::deque<int> sorted_data = btree.dump();
    for (int i : sorted_data)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
