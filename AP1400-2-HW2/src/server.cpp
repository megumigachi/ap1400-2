#include "server.h"
#include <iostream>
#include <random>
#include<sstream>
#include<string>
#include "crypto.h"

using std::make_shared;
using std::map;
using std::shared_ptr;
using std::string;
using std::istringstream;

std::vector<std::string> pending_trxs;

string addRandomString(string origin)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 10);
    string append = "";
    for (size_t i = 0; i < 4; i++)
    {
        append += distribution(generator);
    }
    return origin + append;
}

Server::Server() {}

shared_ptr<Client> Server::add_client(string id)
{
    bool exist = false;
    for (auto &pair : this->clients)
    {
        string _id = pair.first->get_id();
        if (id == _id)
        {
            exist = true;
            break;
        }
    }
    shared_ptr<Client> c;
    if (exist)
    {
        id = addRandomString(id);
    }
    c = make_shared<Client>(id, *this);
    this->clients[c] = 5;
    return c;
}

map<shared_ptr<Client>, double> Server::get_clients() const
{
    return this->clients;
}

shared_ptr<Client> Server::get_client(string id)
{
    shared_ptr<Client> c = nullptr;
    for (auto &pair : this->clients)
    {
        if (pair.first->get_id() == id)
        {
            return pair.first;
        }
    }
    return nullptr;
}

double Server::get_wallet(std::string id)
{
    auto c = this->get_client(id);
    if (c != nullptr)
    {
        return this->clients[c];
    }
    return 0;
}


void show_pending_transactions()
{
    std::cout << std::string(20, '*') << std::endl;
    for (const auto &trx : pending_trxs)
        std::cout << trx << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}

void show_wallets(const Server &server)
{
    std::cout << std::string(20, '*') << std::endl;
    for (const auto &client : server.get_clients())
        std::cout << client.first->get_id() << " : " << client.second << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}

bool Server::parse_trx(std::string trx, std::string &sender, std::string &receiver, double &value)
{
    vector<string> transaction=split(trx,'-');
    if (transaction.size()!=3){
        std::runtime_error e("1");
        throw e;
    }
    
    sender=transaction[0];
    receiver=transaction[1];
    value=std::stod(transaction[2]);
    // try
    // {
    //     value=std::stod(transaction[2]);
    // }
    // catch(const std::exception& e)
    // {
    //     return false;
    // }
    return true;
    //shared_ptr<Client> csender=
    
    
}


bool Server::add_pending_trx(std::string trx, std::string signature){
    //validate signature
    std::string sender{};
    std::string receiver{};
    double value = 0;
    try {
        this->parse_trx(trx, sender, receiver, value);
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    shared_ptr<Client> sd=this->get_client(sender);
    if (sd==nullptr)
    {
        return false;
    }
    crypto::verifySignature(sd->get_publickey(),trx,signature);
    pending_trxs.push_back(trx);
    return true;
}

vector<string>split(string to_split,char delimiter){
    istringstream iss(to_split);
    vector<string>tokens;
    string token;
    while (std::getline(iss,token,delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
// Server