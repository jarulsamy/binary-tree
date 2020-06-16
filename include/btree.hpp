#pragma once

template <class T>
class Node
{
public:
    Node()
    {
        left = nullptr;
        right = nullptr;
    };

    Node(T d)
    {
        Node();
        data = d;
    };

    T data;
    Node *left;
    Node *right;
};

template <class T>
class BTree
{
public:
    BTree()
    {
        root = nullptr;
        height = 0;
    }
    // ~BTree();

    // Add a value to the tree using recursion.
    void insert(T key, Node<T> *leaf)
    {

        if (key < leaf->data)
        {
            if (!leaf->left)
            {
                insert(key, leaf->left);
            }
            else
            {
                leaf->left = new Node<T>(key);
                height++;
            }
        }
        else if (key >= leaf->data)
        {
            if (!leaf->right)
            {
                insert(key, leaf->right);
            }
            else
            {
                leaf->right = new Node<T>(key);
                height++;
            }
        }

        return;
    }

    // Overloaded insert for recursion.
    void insert(T key)
    {
        if (root)
        {
            insert(key, root);
        }
        else
        {
            root = new Node<T>(key);
            height++;
        }
    }
    // Binary search tree for value recursively.
    Node<T> *find(T key, Node<T> *leaf)
    {
        if (leaf != nullptr)
        {
            if (key == leaf->data)
                return leaf;
            else if (key < leaf->data)
                return find(key, leaf->left);
            else
                return find(key, leaf->right);
        }
        else
            return nullptr;
    }

    // Overloaded search for recursion.
    Node<T> *find(T key)
    {
        return find(key, root);
    }

private:
    Node<T> *root;
    int height;
};
