#include "bst.h"
// #include<iostream>
#include <queue>
#include <iomanip>

using Node = BST::Node;
using std::queue;

BST::Node::Node()
{
    this->value = 0;
    this->left = nullptr;
    this->right = nullptr;
}

BST::Node::Node(int value, Node *left, Node *right)
{
    this->value = value;
    this->left = left;
    this->right = right;
}

BST::Node::Node(const Node &node)
{
    this->left = node.left;
    this->right = node.right;
    this->value = node.value;
}

ostream &operator<<(ostream &os, BST::Node node)
{
    os << node.value;
    return os;
}

BST::BST()
{
    this->root = nullptr;
}

BST::Node *BST::get_root()
{
    return this->root;
}

bool BST::add_node(int value)
{
    if (this->root == nullptr)
    {
        this->root = new Node(value, nullptr, nullptr);
        return true;
    }
    Node *n = this->root;
    while (n != nullptr)
    {
        if (n->value == value)
        {
            return false;
        }
        else if (value < *n)
        {
            if (n->left == nullptr)
            {
                n->left = new Node(value, nullptr, nullptr);
                return true;
            }
            else
            {
                n = n->left;
            }
        }
        else
        {
            if (n->right == nullptr)
            {
                n->right = new Node(value, nullptr, nullptr);
                return true;
            }
            else
            {
                n = n->right;
            }
        }
    }
    return false;
}

bool operator==(const BST::Node &node, const int &num)
{
    return node.value == num;
}
bool operator==(const int &num, const BST::Node &node)
{
    return node.value == num;
}
bool operator<(const int &num, const BST::Node &node)
{
    return num < node.value;
}
bool operator<(const BST::Node &node, const int &num)
{
    return node.value < num;
}

bool operator<=(const int &num, const BST::Node &node)
{
    return num <= node.value;
}
bool operator<=(const BST::Node &node, const int &num)
{
    return node.value <= num;
}

bool operator>(const int &num, const BST::Node &node)
{
    return num > node.value;
}
bool operator>(const BST::Node &node, const int &num)
{
    return node.value > num;
}

bool operator>=(const int &num, const BST::Node &node)
{
    return num >= node.value;
}
bool operator>=(const BST::Node &node, const int &num)
{
    return node.value >= num;
}

void BST::bfs(std::function<void(Node *&node)> func)
{
    if (this->root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(this->root);
    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();
        if (n->left != nullptr)
        {
            q.push(n->left);
        }
        if (n->right != nullptr)
        {
            q.push(n->right);
        }
        func(n);
    }
}

size_t BST::length()
{
    return num(this->root);
}

size_t num(BST::Node *n)
{
    if (n == nullptr)
    {
        return 0;
    }
    return 1 + num(n->left) + num(n->right);
}

ostream &operator<<(ostream &os, BST bst)
{
    bst.bfs([](BST::Node *&node)
            { std::cout << node << std::setw(16) << "=>value:" + std::to_string(node->value)
                        << std::setw(16) << node->left
                        << std::setw(16) << node->right
                        << std::endl; });
};

Node **BST::find_node(int value)
{
    if (this->root == nullptr)
    {
        return nullptr;
    }
    Node *ret = this->root;
    while (ret != nullptr)
    {
        if (ret->value == value)
        {
            return &ret;
        }
        else if (value < ret->value)
        {
            ret = ret->left;
        }
        else
        {
            ret = ret->right;
        }
    }
    return &ret;
}