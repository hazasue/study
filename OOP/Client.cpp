#define _CRT_SECURE_NO_WARNIGS
#pragma warning(disable: 4996)

#include "Client.h"
#include <iostream>

using namespace std;

void showMenu() {
	cout << "----- Menu -----" << endl;
	cout << "1. ���� ����			" << endl;
	cout << "2. �� ��				" << endl;
	cout << "3. �� ��				" << endl;
	cout << "4. �������� ��ü ���	" << endl;
	cout << "5. ���� �ı�			" << endl;
	cout << "6. ���α׷� ����		" << endl;
	cout << "����: ";
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
	cout << "[���°���]" << endl;
	cout << "����ID: ";

	cin >> account;
	for (int num = 0; num < 10; num++) { if (client[num]->account == account) { cout << "�̹� �����ϴ� �����Դϴ�." << endl;  return; } }

	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;

	if (money < 0) { cout << "�Աݾ��� ���� ������ �����Ͽ����ϴ�." << endl; return; }

	client[number]->account = account;
	strcpy(client[number]->name, name);
	client[number]->money = money;
}

void deposit(Client* *client) {
	int account;
	int money;

	int count = 0;

	cout << "[�Ա�]" << endl;
	cout << "����ID: ";
	cin >> account;
	for (int num = 0; num < 10; num++) {
		if (client[num]->account == account) {
			cout << "�Աݾ�: ";
			cin >> money;
			if (money < 0) { cout << "����� [���]â���� �̿� ��Ź�帳�ϴ�." << endl; return; }
			client[num]->money += money;
			cout << "�Ա� �Ǿ����ϴ�." << endl;
			break;
		}
		count++;
	}
	if (count >= 10) cout << "�ش��ϴ� ���°� �������� �ʽ��ϴ�." << endl;
}

void withdraw(Client* *client) {
	int account;
	int money;

	int count = 0;

	cout << "[���]" << endl;
	cout << "����ID: ";
	cin >> account;
	for (int num = 0; num < 10; num++) {
		if (client[num]->account == account) {
			cout << "��ݾ�: ";
			cin >> money;
			if (money < 0) { cout << "�Ա��� [�Ա�]â���� �̿� ��Ź�帳�ϴ�." << endl; return; }
			if (client[num]->money >= money) {
				client[num]->money -= money;
				cout << "��� �Ǿ����ϴ�." << endl;
			}
			else
				cout << "�ܾ��� �����մϴ�." << endl;

			break;

		}
		count++;
	}
	if (count >= 10) cout << "�ش��ϴ� ���°� �������� �ʽ��ϴ�." << endl;
}

void showInformation(Client* *client) {
	int account;
	int number = -1;

	cout << "����ID: ";
	cin >> account;
	for (int num = 0; num < 10; num++) { if (client[num]->account == account) number = num; }

	if (number == -1) { cout << "�ش��ϴ� ���°� �������� �ʽ��ϴ�." << endl;  return; }

	cout << "�̸�: " << client[number]->name << endl;

	cout << "�ܾ�: " << client[number]->money << endl;
}

void deleteAccount(Client* *client) {
	int account;
	cout << "����ID: ";
	cin >> account;

	for (int num = 0; num < 10; num++) { if (client[num]->account = account) free(client[num]); client[num] = new Client{}; }
	cout << "���°� �ı�Ǿ����ϴ�." << endl;
}

void stop() {
	cout << "���α׷��� �����մϴ�." << endl;
}