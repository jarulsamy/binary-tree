#ifndef BTREE_HPP
#define BTREE_HPP

#include <deque>

template <typename T>
class Node
{
public:
    Node(T d)
    {
        left = nullptr;
        right = nullptr;
        value = d;
    };

    T value;
    Node<T> *left;
    Node<T> *right;
};

template <typename T>
class BTree
{

public:
    BTree() { root = nullptr; };
    BTree(T r_value) { root = new Node<T>(r_value); }
    ~BTree() { destroy(root); }

    void insert(T val) { insert(val, root); }
    bool find(T val) { return find(val, root); }

    std::deque<T> dump()
    {
        std::deque<T> result;
        dump(result, root);
        return result;
    }

private:
    void destroy(Node<T> *&node)
    {
        if (node)
        {
            destroy(node->right);
            destroy(node->left);
            delete (node);
        }
    }

    void insert(T val, Node<T> *&node)
    {
        if (node == nullptr)
            node = new Node<T>(val);
        else if (val > node->value)
            insert(val, node->right);
        else if (val < node->value)
            insert(val, node->left);
    }

    bool find(T val, Node<T> *&node)
    {
        if (node)
        {
            if (val == node->value)
                return true;
            else if (val > node->value)
                return find(val, node->right);
            else if (val < node->value)
                return find(val, node->left);
        }

        return false;
    }

    void dump(std::deque<T> &buffer, Node<T> *&node)
    {
        if (node != nullptr)
        {
            dump(buffer, node->left);
            buffer.push_back(node->value);
            dump(buffer, node->right);
        }
    }

    Node<T> *root;
};

#endif
