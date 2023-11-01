# Binary Search Tree

An implementation of binary search trees using shared pointers

## Overview

A **Binary Search Tree (BST)** is a node-based data structure.

Binary search requires that we have access to two elements, specifically the median elements about and below the given node. This repository uses a **header-only** file `binary_search_tree.h` that handles the basic operations of a Binary Search Tree: insertion, searching, traversing, and removal (or deletion). The program uses `std::shared_ptr` to store the trees.

## Build and Run

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

## Example Usage

``` CPP
#include <iostream>
#include <memory>
#include "binary_search_tree.h"

int main(int argc, char** argv)
{
    auto rootNode = std::make_shared<tree<int>>(50, nullptr, nullptr);
    auto binarySearchTree = std::make_shared<binary_search_tree<int>>();
    
    // Insert nodes after the root node
    binarySearchTree->insert_tree(rootNode, 30);
    binarySearchTree->insert_tree(rootNode, 70);
    binarySearchTree->insert_tree(rootNode, 20);
    binarySearchTree->insert_tree(rootNode, 40);
    binarySearchTree->insert_tree(rootNode, 60);
    binarySearchTree->insert_tree(rootNode, 80);
    binarySearchTree->insert_tree(rootNode, 10);
    binarySearchTree->insert_tree(rootNode, 45);
    binarySearchTree->insert_tree(rootNode, 65);
    binarySearchTree->insert_tree(rootNode, 90);
    
    std::cout << "Tree Node Count:" << " " << binarySearchTree->get_tree_count(rootNode) << "\n" << std::endl;
    
    // Traverse the tree nodes
    binarySearchTree->traverse_tree(rootNode);
    
    // Remove nodes from the tree
    binarySearchTree->remove_tree(rootNode, 50);
    binarySearchTree->remove_tree(rootNode, 30);
    binarySearchTree->remove_tree(rootNode, 70);
    binarySearchTree->remove_tree(rootNode, 20);
    binarySearchTree->remove_tree(rootNode, 40);
    binarySearchTree->remove_tree(rootNode, 60);
    binarySearchTree->remove_tree(rootNode, 80);
    binarySearchTree->remove_tree(rootNode, 10);
    binarySearchTree->remove_tree(rootNode, 45);
    binarySearchTree->remove_tree(rootNode, 65);
    binarySearchTree->remove_tree(rootNode, 90);
    
    rootNode.reset();
    binarySearchTree.reset();
           
    return 0;
}


```
