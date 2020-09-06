#ifndef BTREE_HPP
#define BTREE_HPP

#include <deque>

/**
 * @brief A member of a binary search tree.
 *
 * @tparam T some data to hold
 */
template <typename T>
class Node
{
public:
    Node(T d) : value(d)
    {
        left = nullptr;
        right = nullptr;
    };

    T value;
    Node<T> *left;
    Node<T> *right;
};

/**
 * @brief A binary search tree
 *
 * @tparam T Optional, value of root node.
 * If not specified, is later created upon first insertion.
 */
template <typename T>
class BTree
{

public:
    /**
     * @brief Construct a new BTree object.
     * By default, the root is nullptr.
     *
     */
    BTree()
    {
        root = nullptr;
    };
    /**
     * @brief Construct a new BTree object.
     *
     * @param r_value Define the root value
     */
    BTree(T r_value)
    {
        root = new Node<T>(r_value);
    }
    /**
     * @brief Destroy the BTree object.
     * Initiates a recursive function.
     *
     */
    ~BTree()
    {
        destroy(root);
    }

    /**
     * @brief Insert a value into the tree,
     * initiates a recursive function.
     *
     * @param val
     */
    void insert(T val) { insert(val, root); }

    /**
     * @brief Determine if a value is in the tree,
     * initiates a recursive function.
     *
     * @param val
     * @return true
     * @return false
     */
    bool find(T val) { return find(val, root); }

    /**
     * @brief Dump data in ascending order.
     *
     * @return std::deque<T>
     */
    std::deque<T> dump()
    {
        std::deque<T> result;
        dump(result, root);
        return result;
    }

private:
    /**
     * @brief Recursively delete subtrees
     * @short Delete right and left subtrees, then delete self.
     * @param node
     */
    void destroy(Node<T> *&node)
    {
        if (node)
        {
            destroy(node->right);
            destroy(node->left);
            delete (node);
        }
    }

    /**
     * @brief Insert a value into a subtree
     *
     * @short Recursively calls self with new subtrees
     *
     * @param val Value to insert
     * @param node Root of subtree
     */
    void insert(T val, Node<T> *&node)
    {
        if (node == nullptr)
            node = new Node<T>(val);
        else if (val > node->value)
            insert(val, node->right);
        else if (val < node->value)
            insert(val, node->left);
    }

    /**
     * @brief Find a value in a subtree
     *
     * @short Recursively calls self with new subtrees
     *
     * @param val Value to find
     * @param node Root of subtree
     * @return true
     * @return false
     */
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

    /**
     * @brief Dumps tree to subtree
     *
     * @short Recursively uses prefix order to dump data in ascending order
     *
     * @param buffer Reference to output dequeue, carried to add values to
     * @param node Root of subtree
     */
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
