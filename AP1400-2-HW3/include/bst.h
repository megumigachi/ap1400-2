#ifndef BST_H
#define BST_H

#include<iostream>

using std::ostream;

class BST{
public:
    class Node
    {
    public:
        Node(int value, Node* left, Node* right);
        Node();
        Node(const Node& node);

        int value;
        Node* left;
        Node* right;
    };

    BST();
    Node* get_root();
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);
private:
    Node* root;
};


ostream& operator<<(ostream& os,BST::Node node);
bool operator==(const BST::Node& node, const int& num);
bool operator==(const int& num, const BST::Node& node);

bool operator<(const int& num, const BST::Node& node);
bool operator<(const BST::Node& node, const int& num);

bool operator<=(const int& num, const BST::Node& node);
bool operator<=(const BST::Node& node, const int& num);

bool operator>(const int& num, const BST::Node& node);
bool operator>(const BST::Node& node, const int& num);

bool operator>=(const int& num, const BST::Node& node);
bool operator>=(const BST::Node& node, const int& num);


#endif 
//BST_H