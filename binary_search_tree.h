/* 
 * MIT License
 * Copyright (c) 2018 Robert Slattery
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>

/*
 * binary_search_tree.h
 * 
 * The basic operations of a binary search tree include searching, traversal,
 * insertion, and removal (or deletion).
 */

template<typename Key>
struct tree
{
    union
    {
        struct
        {
            Key key;
            std::shared_ptr<tree<Key>> left;
            std::shared_ptr<tree<Key>> right;
        };
    };
    
    inline Key get_key() const { return key; }
    
    inline std::shared_ptr<tree<Key>> get_left_child() const { return left; }
    inline void set_left_child(const std::shared_ptr<tree<Key>>& _l) { left = _l; }
    
    inline std::shared_ptr<tree<Key>> get_right_child() const { return right; }
    inline void set_right_child(const std::shared_ptr<tree<Key>>& _r) { right = _r; }
        
    tree(
        const Key& _key
      , const std::shared_ptr<tree<Key>>& _left
      , const std::shared_ptr<tree<Key>>& _right) :
        key(_key)
      , left(_left)
      , right(_right)
    {}
    
    bool operator==(const tree<Key>& lhs)
    {
        return (
            lhs.key == key
         && lhs.left == left 
         && lhs.right == right);
    }
};

template<typename Key>
class binary_search_tree
{

public:
    
    // Constructor
    explicit binary_search_tree<Key>() {}
    
    // Destructor
    ~binary_search_tree<Key>() {}
    
    // Searching
    std::shared_ptr<tree<Key>> search_tree(const std::shared_ptr<tree<Key>>& _tree, const Key& _key) const;
    
    // Traversing
    void traverse_tree(const std::shared_ptr<tree<Key>>& _tree) const;

    // Removal
    std::shared_ptr<tree<Key>> remove_tree(std::shared_ptr<tree<Key>> _current, Key _key);
    
    // Insertion
    std::shared_ptr<tree<Key>> insert_tree(const std::shared_ptr<tree<Key>>& _tree, const Key& _key);
    
    // Finding minimum element (left)
    std::shared_ptr<tree<Key>> find_minimum(const std::shared_ptr<tree<Key>>& _tree) const;
    
    // Finding maximum element (right)
    std::shared_ptr<tree<Key>> find_maximum(const std::shared_ptr<tree<Key>>& _tree) const;
    
    int get_tree_count(const std::shared_ptr<tree<Key>>& _current) const;
    
    void print_key(const std::shared_ptr<tree<Key>>& _root) const;
     
protected:

    // Copy Constructor
    binary_search_tree(const binary_search_tree&) = delete;
    binary_search_tree(binary_search_tree&&) = delete;
    
    // Copy-Assignment Operator
    binary_search_tree& operator=(const binary_search_tree& _tree) { return *this; }
    
private:

    std::shared_ptr<tree<Key>> create_tree(const Key& _key);
    
};
 
// Searching for a key
template<typename Key>
inline std::shared_ptr<tree<Key>> binary_search_tree<Key>::search_tree(const std::shared_ptr<tree<Key>>& _tree, const Key& _key) const
{
    if (_tree == nullptr) return nullptr;

    if (_tree->get_key() == _key) return _tree;
    
    if (_key < _tree->get_key()) 
        return (search_tree(_tree->get_left_child(), _key));
    else 
        return (search_tree(_tree->get_right_child(), _key));
}

// Visit all the trees in order
template<typename Key>
inline void binary_search_tree<Key>::traverse_tree(const std::shared_ptr<tree<Key>>& _tree) const
{
   if (_tree != nullptr)
   {
       traverse_tree(_tree->get_left_child());
       std::cout << _tree->get_key() << "\n" << std::endl;
       traverse_tree(_tree->get_right_child());
   }
}

// Removal
template<typename Key>
inline std::shared_ptr<tree<Key>> binary_search_tree<Key>::remove_tree(std::shared_ptr<tree<Key>> _current, Key _key)
{
    if (!_current) return nullptr;
    
    // Calls for ancestors of tree to be deleted
    if (_current->get_key() > _key)
    {
        _current->left = remove_tree(_current->get_left_child(), _key);
        return _current;
    }
    else if (_current->get_key() < _key)
    {
        _current->right = remove_tree(_current->get_right_child(), _key);
        return _current;
    }
    
    //
    // Now _current is the tree to be deleted
    //
    
    // If one of the children is empty
    if (_current->get_left_child() == nullptr)
    {
        std::shared_ptr<tree<Key>> temp = _current->get_right_child();

        _current.reset();
        
        return temp;
    }
    else if (_current->get_right_child() == nullptr)
    {
        std::shared_ptr<tree<Key>> temp = _current->get_left_child();
        
         _current.reset();
        
        return temp;
    }
    else // If both children exist
    {
        std::shared_ptr<tree<Key>> successor_parent = _current->get_right_child();
        
        // Find successor
        std::shared_ptr<tree<Key>> successor = _current->get_right_child();
        
        while (successor->get_left_child() != nullptr)
        {
            successor_parent = successor;
            successor = successor->get_left_child();
        }
        
        // Since successor is always left child of its parent
        // we can safely make successor's right right child as left of its parent.
        successor_parent->left = successor->get_right_child();
        
        // Copy successor data to _current;
        _current->key = successor->get_key();
        
        // Reset successor. 
        successor.reset();
        
        return _current;
    }
}

template<typename Key>
inline std::shared_ptr<tree<Key>> binary_search_tree<Key>::create_tree(const Key& _key)
{
    auto temp_tree = std::make_shared<tree<Key>>(0, nullptr, nullptr);
    temp_tree->key = _key;
    temp_tree->left = temp_tree->right = nullptr;
    return temp_tree;
}

template<typename Key>
inline std::shared_ptr<tree<Key>> binary_search_tree<Key>::insert_tree(const std::shared_ptr<tree<Key>>& _tree, const Key& _key)
{
    if (_tree == nullptr) 
        return create_tree(_key);
    
    (_key < (_tree)->key) 
        ? _tree->left = insert_tree(_tree->get_left_child(), _key) 
        : _tree->right = insert_tree(_tree->get_right_child(), _key);
    
    return _tree;
}

template<typename Key>
inline std::shared_ptr<tree<Key>> binary_search_tree<Key>::find_minimum(const std::shared_ptr<tree<Key>>& _tree) const
{
    if (_tree == nullptr) return nullptr;

    std::shared_ptr<tree<Key>> min = _tree;

    while (min->get_left_child() != nullptr)
        min = min->get_left_child();

    return min;
}

template<typename Key>
inline std::shared_ptr<tree<Key>> binary_search_tree<Key>::find_maximum(const std::shared_ptr<tree<Key>>& _tree) const
{
    if (_tree == nullptr) return nullptr;

    std::shared_ptr<tree<Key>> max = _tree;

    while (max->get_right_child() != nullptr)
        max = max->get_right_child();

    return max;
}

template<typename Key>
inline int binary_search_tree<Key>::get_tree_count(const std::shared_ptr<tree<Key>>& _current) const
{
    if (!_current) return 0;
    else return 1 + get_tree_count(_current->get_left_child()) + get_tree_count(_current->get_right_child());
}

template<typename Key>
inline void binary_search_tree<Key>::print_key(const std::shared_ptr<tree<Key>>& _root) const
{
    if (!_root) return;
    std::cout << _root->get_key() << std::endl;
}
    
#endif /* BINARY_SEARCH_TREE_H */

