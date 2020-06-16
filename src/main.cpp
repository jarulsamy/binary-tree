#include <iostream>
#include <deque>
#include <string>

#include "btree.hpp"
#include "loader.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    if (argc != 2)
        cout << "Usage: ./btree.o FILENAME.txt" << endl;
    std::deque<int> data = load(argv[1]);

    BTree<int> btree;
    int buffer;

    for (int i : data)
        btree.insert(i);

    cout << "Enter a number to find: ";
    cin >> buffer;
    if (btree.find(buffer))
        cout << "Found!" << endl;
    else
        cout << "Not found!" << endl;

    return 0;
}
