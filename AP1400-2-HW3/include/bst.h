#ifndef BST_H
#define BST_H

#include <iostream>
#include <functional>
#include <initializer_list>

using std::ostream;

class BST
{
public:
    class Node
    {
    public:
        Node(int value, Node *left, Node *right);
        Node();
        Node(const Node &node);

        int value;
        Node *left;
        Node *right;
    };

    BST();
    BST(std::initializer_list<int> initList);
    Node *get_root();
    size_t length();
    bool add_node(int value);
    Node **find_node(int value);
    Node **find_parrent(int value);
    Node **find_successor(int value);
    bool delete_node(int value);
    void bfs(std::function<void(Node *&node)> func);

private:
    Node *root;
    size_t length_cnt;
};

ostream &operator<<(ostream &os, BST bst);
ostream &operator<<(ostream &os, BST::Node node);
bool operator==(const BST::Node &node, const int &num);
bool operator==(const int &num, const BST::Node &node);

bool operator<(const int &num, const BST::Node &node);
bool operator<(const BST::Node &node, const int &num);

bool operator<=(const int &num, const BST::Node &node);
bool operator<=(const BST::Node &node, const int &num);

bool operator>(const int &num, const BST::Node &node);
bool operator>(const BST::Node &node, const int &num);

bool operator>=(const int &num, const BST::Node &node);
bool operator>=(const BST::Node &node, const int &num);

size_t num(BST::Node *n);

#endif
// BST_H