//Check Github Push
#define _CRT_SECURE_NO_WARNIGS
#pragma warning(disable: 4996)

#include <iostream>
#include <stdio.h>
#include <string>
#include "Client.h"

using namespace std;

int main() {
	Client* client[10]{};

	for (int i = 0; i < 10; i++) { client[i] = new Client{}; }

	while (1) {
		showMenu();
		int num;

		cin >> num;

		switch (num) {
		case 1:
			system("cls");
			createAccount(client);
			break;
		case 2:
			system("cls");
			deposit(client);
			break;
		case 3:
			system("cls");
			withdraw(client);
			break;
		case 4:
			system("cls");
			showInformation(client);
			break;
		case 5:
			system("cls");
			deleteAccount(client);
			break;
		case 6:
			stop();
			return 0;
			break;
		}
	}
}
