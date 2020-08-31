# Binary-Tree

A simple binary search tree implementation in C++

## Rationale

I got bored one night and thought that I would write a simple application demonstrating a binary search tree. This one specifically only works with integers, but can easily be expanded to more data types since most of the code is already templated.

### Learning Concepts

Some of the things this project helped me learn:

* Pointers
* Dynamic memory allocation
* Recursion
* Object oriented programming
* `argp` Argument parsing
* File IO

## Building

Clone the and `cd` into the repository:

```bash
git clone https://github.com/jarulsamy/binary-tree
cd binary-tree
```

Create a build directory:

```bash
mkdir build
cd build
```

Generate the cmake build files

```bash
cmake ..
```

Finally, build:

```bash
make
```

The binary will be built to `build/bin/btree.o`

### Usage

Built-in help

```bash
$ bin/btree.o --help

sage: btree.o [OPTION...] PATH_OF_INPUT_TXT
A simple example of binary search trees.

  -o, --output=FILE          Output to FILE instead of standard output
  -?, --help                 Give this help list
      --usage                Give a short usage message

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.
```

Demo:

```bash
$ bin/btree.o ../data.txt
26
27
31

. . .

9961
9968
9992
```
