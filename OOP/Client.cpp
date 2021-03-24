#define _CRT_SECURE_NO_WARNIGS
#pragma warning(disable: 4996)

#include "Client.h"
#include <iostream>

using namespace std;

void showMenu() {
	cout << "----- Menu -----" << endl;
	cout << "1. 계좌 개설			" << endl;
	cout << "2. 입 금				" << endl;
	cout << "3. 출 금				" << endl;
	cout << "4. 계좌정보 전체 출력	" << endl;
	cout << "5. 계좌 파기			" << endl;
	cout << "6. 프로그램 종료		" << endl;
	cout << "선택: ";
}

void createAccount(Client* *client) {
	int account;
	char name[10];
	int money;

	int number = 0;
	for (int num = 0; num < 10; num++) {
		if (client[num]->account != -1) continue;
		else {
			number = num;
			break;
		}

	}
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";

	cin >> account;
	for (int num = 0; num < 10; num++) { if (client[num]->account == account) { cout << "이미 존재하는 계좌입니다." << endl;  return; } }

	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;

	if (money < 0) { cout << "입금액이 적어 개설에 실패하였습니다." << endl; return; }

	client[number]->account = account;
	strcpy(client[number]->name, name);
	client[number]->money = money;
}

void deposit(Client* *client) {
	int account;
	int money;

	int count = 0;

	cout << "[입금]" << endl;
	cout << "계좌ID: ";
	cin >> account;
	for (int num = 0; num < 10; num++) {
		if (client[num]->account == account) {
			cout << "입금액: ";
			cin >> money;
			if (money < 0) { cout << "출금은 [출금]창구를 이용 부탁드립니다." << endl; return; }
			client[num]->money += money;
			cout << "입금 되었습니다." << endl;
			break;
		}
		count++;
	}
	if (count >= 10) cout << "해당하는 계좌가 존재하지 않습니다." << endl;
}

void withdraw(Client* *client) {
	int account;
	int money;

	int count = 0;

	cout << "[출금]" << endl;
	cout << "계좌ID: ";
	cin >> account;
	for (int num = 0; num < 10; num++) {
		if (client[num]->account == account) {
			cout << "출금액: ";
			cin >> money;
			if (money < 0) { cout << "입금은 [입금]창구를 이용 부탁드립니다." << endl; return; }
			if (client[num]->money >= money) {
				client[num]->money -= money;
				cout << "출금 되었습니다." << endl;
			}
			else
				cout << "잔액이 부족합니다." << endl;

			break;

		}
		count++;
	}
	if (count >= 10) cout << "해당하는 계좌가 존재하지 않습니다." << endl;
}

void showInformation(Client* *client) {
	int account;
	int number = -1;

	cout << "계좌ID: ";
	cin >> account;
	for (int num = 0; num < 10; num++) { if (client[num]->account == account) number = num; }

	if (number == -1) { cout << "해당하는 계좌가 존재하지 않습니다." << endl;  return; }

	cout << "이름: " << client[number]->name << endl;

	cout << "잔액: " << client[number]->money << endl;
}

void deleteAccount(Client* *client) {
	int account;
	cout << "계좌ID: ";
	cin >> account;

	for (int num = 0; num < 10; num++) { if (client[num]->account = account) free(client[num]); client[num] = new Client{}; }
	cout << "계좌가 파기되었습니다." << endl;
}

void stop() {
	cout << "프로그램을 종료합니다." << endl;
}