#include "server.h"
#include <iostream>

using std::make_shared;
using std::shared_ptr;
using std::string;

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
        /* code */
    }else{
         c =make_shared<Client>(id,*this);
    }
     this->clients[c]=5;
     return c;
}

// Server