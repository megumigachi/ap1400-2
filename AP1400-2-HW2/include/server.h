#ifndef SERVER_H
#define SERVER_H

#include "client.h"
#include <iostream>
#include <memory>
#include <map>
#include<vector>

using std::vector;
using std::string;
class Client;

class Server
{
public:
	Server();
	std::shared_ptr<Client> add_client(std::string id);
	std::shared_ptr<Client> get_client(std::string id);
	double get_wallet(std::string id);
	static bool parse_trx(std::string trx, std::string &sender, std::string &receiver, double &value);
	bool add_pending_trx(std::string trx, std::string signature);
	size_t mine();
	std::map<std::shared_ptr<Client>, double> get_clients() const;

private:
	std::map<std::shared_ptr<Client>, double> clients;
};

void show_wallets(const Server &server);
void show_pending_transactions();
vector<string>split(string to_split, char delimiter);


#endif // SERVER_H