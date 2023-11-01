# Binary Search Tree
An implementation of binary search trees using shared pointers

## OVERVIEW

A **Binary Search Tree (BST)** is a node-based data structure.

Binary search requires that we have access to two elements, specifically the median elements about and below the given node.  This repository uses a **header-only** file `binary_search_tree.h` that handles the basic operations of a Binary Search Tree: insertion, searching, traversing, and removal (or deletion).  The program uses `std::shared_ptr` to store the trees.

## BUILD AND RUN

Tested for `C++11` and `C++14` and compiled with `g++ 6.3.0`.

### GNU/Linux Users

**1. Compile from terminal**

```
cd <directory>
g++ -std=c++14 -c main.cpp
g++ -std=c++14 -o bst.exe main.o
```

**2. Run the program**

```
./bst.exe
```

## EXAMPLE USAGE

```c++
#include <iostream>
#include <memory>
#include "binary_search_tree.h"

int main(int argc, char** argv)
{
    auto root = std::make_shared<tree<int>>(20, nullptr, nullptr);
    auto bst = std::make_shared<binary_search_tree<int>>();
    
    // Insert trees after root
    bst->insert_tree(root, 12);
    bst->insert_tree(root, 4);
    bst->insert_tree(root, 500);
    bst->insert_tree(root, 68);
    bst->insert_tree(root, 497);
    
    std::cout << "Tree Count:" << " " << bst->get_tree_count(root) << "\n" << std::endl;
    
    // Traverse trees
    bst->traverse_tree(root);
    
    // Remove trees
    bst->remove_tree(root, 20);
    bst->remove_tree(root, 12);
    bst->remove_tree(root, 4);
    bst->remove_tree(root, 500);
    bst->remove_tree(root, 68);
    bst->remove_tree(root, 497);
    
    root.reset();
    bst.reset();
           
    return 0;
}
```

## LICENSE

> MIT License
>
> Copyright (c) 2018 Robert Slattery
> 
> Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
