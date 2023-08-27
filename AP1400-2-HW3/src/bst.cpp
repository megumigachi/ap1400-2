#include "bst.h"
//#include<iostream>

using Node=BST::Node;

BST::Node::Node()
{
    this->value=0;
    this->left=nullptr;
    this->right=nullptr;
}

BST::Node::Node(int value, Node* left, Node* right)
{
    this->value=value;
    this->left=left;
    this->right=right;
}

BST::Node::Node(const Node  &node){
    this->left=node.left;
    this->right=node.right;
    this->value=node.value;
}

ostream& operator<<(ostream& os,BST::Node node){
    os<<node.value;
    return os;
}

BST::BST(){
    this->root=nullptr;
}

BST::Node* BST::get_root(){
    return this->root;
}

bool BST::add_node(int value){
    if (this->root==nullptr)
    {
        this->root=new Node(value,nullptr,nullptr);
        return true;
    }
    Node* n=this->root;
    while (n!=nullptr)
    {
        if (n->value==value)
        {
            return false;
        }else if (value<*n)
        {
            if (n->left==nullptr)
            {
                n->left=new Node(value,nullptr,nullptr);
                return true;
            }else{
                n=n->left;
            }
        }else{
            if (n->right==nullptr)
            {
                n->right=new Node(value,nullptr,nullptr);
                return true;
            }else{
                n=n->right;
            }
            
        }

    }
    return false;
    
}


bool operator==(const BST::Node& node, const int& num){
    return node.value==num;
}
bool operator==(const int& num, const BST::Node& node){
    return node.value==num;
}
bool operator<(const int& num, const BST::Node& node){
    return num<node.value;
}
bool operator<(const BST::Node& node, const int& num){
    return node.value<num;
}

bool operator<=(const int& num, const BST::Node& node){
    return num<=node.value;
}
bool operator<=(const BST::Node& node, const int& num){
    return node.value<=num;
}

bool operator>(const int& num, const BST::Node& node){
    return num>node.value;
}
bool operator>(const BST::Node& node, const int& num){
    return node.value>num;
}

bool operator>=(const int& num, const BST::Node& node){
    return num>=node.value;
}
bool operator>=(const BST::Node& node, const int& num){
    return node.value>=num;
}
