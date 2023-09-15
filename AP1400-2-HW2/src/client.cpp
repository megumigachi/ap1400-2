#include "client.h"
#include "crypto.h"

using std::string;

Client::Client(string id, const Server &server)
    : id(id), server(&server)
{
    string pub_key{}, pri_key{};
    crypto::generate_key(pub_key, pri_key);
    this->public_key = pub_key;
    this->private_key = pri_key;
}

string Client::get_id()
{
    return this->id;
}

double Client::get_wallet()
{
    return ((Server *)(this->server))->get_wallet(this->id);
}

string Client::get_publickey() const
{
    return this->public_key;
}

string Client::sign(string txt) const
{
    return crypto::signMessage(this->private_key, txt);
}

bool Client::transfer_money(std::string receiver, double value)
{
    string trx = this->id + "-" + receiver + "-" + std::to_string(value);
    string signature = this->sign(trx);
    Server *s = (Server *)this->server;
    return s->add_pending_trx(trx, signature);
}

size_t Client::generate_nonce()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 9);
    return distribution(generator);
}