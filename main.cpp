// Client

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <winsock2.h>

using namespace std;

int main()
{

	cout << "Client: " << endl;

	char ip[17];
	u_short port;
	char message[300];

	cout << "IP: ";
	cin >> ip;
	cout << endl;

	cout << "Port: ";
	cin >> port;
	cout << endl;

	WSAData wsa;
	WORD Version = MAKEWORD(2, 1);

	WSAStartup(Version, &wsa);

	if (WSAStartup(Version, &wsa) != 0)
	{

		cout << "Невозможно загрузить библиотеку WSA." << endl;

	}
	else
	{

		cout << "Библиотека WSA загружена." << endl;

	}

	SOCKET SendSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

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
	SendS.sin_addr.s_addr = inet_addr(ip);

	while (1)
	{

		if (connect(SendSock, (SOCKADDR*)&SendSock, sizeof(SendSock)))
		{

			cout << "Соединение с сервером установлено." << endl;

			send(SendSock, "Сообщение от клиента: соединение с клиентом установлено.", 300, 0);

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
