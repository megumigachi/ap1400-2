#include "client.h"

using std::string;

Client::Client(string id, const Server &server)
    : id(id), server(&server)
{
}