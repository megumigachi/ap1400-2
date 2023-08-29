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
    return os;
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
            auto ret_ = new Node *(ret);
            return ret_;
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
    return nullptr;
}

Node **BST::find_parrent(int value)
{
    Node *p = this->root;
    Node *ret = nullptr;
    while (p != nullptr)
    {
        if (p->value == value)
        {
            return new Node *(ret);
        }
        else if (value < p->value)
        {
            ret = p;
            p = p->left;
        }
        else
        {
            ret = p;
            p = p->right;
        }
    }
    return nullptr;
}

// 这个函数本来名字都错了，懒得写了
BST::Node **BST::find_successor(int value)
{
    if (root == nullptr)
        return nullptr;
    auto b = find_node(value);
    if (b == nullptr || (*b)->left == nullptr)
    {
        delete b;
        return nullptr;
    }
    auto p = (*b)->left;
    while (p != nullptr && p->right != nullptr)
    {
        p = p->right;
    }
    if (p == nullptr)
    {
        return nullptr;
    }

    auto res{new Node *{p}};
    delete b;
    return res;
}

// 太啥b了
bool BST::delete_node(int value)
{
    auto node = find_node(value);
    auto parent = find_parrent(value);

    if (node == nullptr)
    {
        return false;
    }

    if ((*node)->left == nullptr && (*node)->right == nullptr)
    {
        if (get_root() == *node)
            root = nullptr;
        else
        {
            if (value > (*parent)->value)
                (*parent)->right = nullptr;
            else
                (*parent)->left = nullptr;
        }
    }
    else if ((*node)->left != nullptr && (*node)->right != nullptr)
    {
        auto next = find_successor(value);
        auto new_one = new Node{(*next)->value, (*node)->left, (*node)->right};
        delete_node((*next)->value);
        delete next;
        if (get_root() == *node)
        {
            new_one->left = root->left;
            new_one->right = root->right;
            root = new_one;
        }
        else
        {
            if ((*parent)->left == *node)
                (*parent)->left = new_one;
            else
                (*parent)->right = new_one;
        }
    }
    else
    {
        Node *new_one = nullptr;
        if ((*node)->left)
            new_one = (*node)->left;
        else
            new_one = (*node)->right;

        if (root == *node)
        {
            new_one->left = root->left;
            new_one->right = root->right;
            root = new_one;
        }
        else
        {
            if ((*parent)->left == *node)
                (*parent)->left = new_one;
            else
                (*parent)->right = new_one;
        }
    }
    delete *node;
    delete node;
    delete parent;

    return true;
}

BST::BST(std::initializer_list<int> initList)
{
    this->root = nullptr;
    for (auto &i : initList)
    {
        this->add_node(i);
    }
}