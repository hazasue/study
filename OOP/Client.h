#pragma once
class Client {
public:
	char	name[100];
	int		account;
	int		money;
	bool	usedAccount;

	Client(const char* name = "", int account = -1, int money = 0)
		:usedAccount(false)
	{}
};

void showMenu();
void createAccount(Client* *client);
void deposit(Client* *client);
void withdraw(Client* *client);
void showInformation(Client* *client);
void deleteAccount(Client* *client);
void stop();

