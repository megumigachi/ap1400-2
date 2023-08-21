#include "client.h"

using std::string;

Client::Client(string id, const Server &server)
    : id(id), server(&server)
{}

string Client::get_id(){
    return this->id;
}

