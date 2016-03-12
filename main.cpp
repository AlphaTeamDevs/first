#include "stdafx.h"
#include <Ws2tcpip.h>
#include <clocale>
#include <iostream>
#include <windows.h>
#include <winsock2.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "                   ##########################################" << endl;
	cout << "                   #                                        #" << endl;
	cout << "                   #             This is Client             #" << endl;
	cout << "                   #                                        #" << endl;
	cout << "                   ##########################################" << endl;

	cout << endl;
	char ip[17];
	u_short port;
	char message[80] = { 0 };

	cout << "Введите IP: ";
	cin >> ip;
	cout << endl;

	cout << "Введите Port: ";
	cin >> port;
	cout << endl;

	WSAData wsa;
	WORD Version = MAKEWORD(1, 1);

	WSAStartup(Version, &wsa);

	if (WSAStartup(Version, &wsa) != 0)
	{

		cout << "Невозможно загрузить библиотеку WSA." << endl;

	}
	else
	{

		cout << "Библиотека WSA загружена." << endl;

	}

	SOCKET SendSock = socket(AF_INET, SOCK_STREAM, 0);

	if (SendSock == SOCKET_ERROR)
	{

		cout << "Невозможно создать сокет." << endl;

	}
	else
	{

		cout << "Сокет создан." << endl;

	}

	SOCKADDR_IN SendS;

	SendS.sin_family = AF_INET;
	SendS.sin_port = htons(port);
	SendS.sin_addr.s_addr = INADDR_ANY; //inet_pton(AF_INET, ip, &(SendS.sin_addr));

	while (1)
	{

		if (connect(SendSock, (SOCKADDR*)&SendS, sizeof(SendS)))
		{

			cout << "Соединение с сервером установлено." << endl;
			cout << endl;

			send(SendSock, "Сообщение от клиента: соединение с клиентом установлено.", 100, 0);
			if (send(SendSock, "Сообщение от клиента: соединение с клиентом установлено.", 100, 0) != 0)
			{

				cout << "Сообщение не отправлено!" << endl;

			}
			else
			{

				cout << "Сообщение отправлено)" << endl;

			}
			// написать про ошибку
			recv(SendSock, message, sizeof(message), 0);

			break;

		}

	}

	cout << message << endl;

	closesocket(SendSock);
	WSACleanup();
	system("pause");
	return 0;

}
