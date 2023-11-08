

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

