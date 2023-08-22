#include "server.h"
#include <iostream>
#include<random>


using std::make_shared;
using std::shared_ptr;
using std::string;


string addRandomString(string origin){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0,10);
    string append="";
    for (size_t i = 0; i < 4; i++)
    {
        append+=distribution(generator);
    }
    return origin+append;
}

Server::Server() {}

shared_ptr<Client> Server::add_client(string id)
{
    bool exist=false;
    for (auto &pair : this->clients)
    {
        string _id=pair.first->get_id();
        if (id==_id)
        {
            exist=true;
            break;
        }
    }
    shared_ptr<Client> c;
    if (exist)
    {
        id=addRandomString(id);
    }
    c =make_shared<Client>(id,*this);
     this->clients[c]=5;
     return c;
}


shared_ptr<Client>Server::get_client(string id){
    shared_ptr<Client>c=nullptr;
    for (auto &pair : this->clients)
    {
        if (pair.first->get_id()==id)
        {
            return pair.first;
        }
    }
    return nullptr;
}

double Server::get_wallet(std::string id){
    auto c=this->get_client(id);
    if (c!=nullptr)
    {
        return this->clients[c];
    }
    return 0;
    
}


// Server