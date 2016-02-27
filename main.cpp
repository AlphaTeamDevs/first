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
    
    if(WSAStartup(Version, &wsa) != 0)
    {
                           
        cout << "Невозможно загрузить библиотеку WSA." << endl;
                           
    }
    else
    {
        
        cout << "Библиотека WSA загружена." << endl; 
        
    }
    
    SOCKET send_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(send_sock == SOCKET_ERROR)
    {
               
        cout << "Невозможно создать сокет." << endl;
               
    }
    else
    {
        
        cout << "Сокет создан." << endl;
        
    }
    
    SOCKADDR_IN send_sock;    
    
    Client.sin_family = AF_INET;
    Client.sin_port = htons(port);
    Client.sin_addr.s_addr = inet_addr(ip);
    
    while(1)
    {
               
        if(connect(send_sock, (SOCKADDR*)&Client, sizeof(Client)))
        {
                            
            cout << "соединение с сервером установлено." << endl;
            
            send(send_sock, "Сообщение от клиента: соединение с клиентом установлено.", 300, 0);
            
            recv(send_sock, message, sizeof(message), 0);
            
            break;
        
        }
        
    }
    
    cout << message << endl;
    
    closesocket(send_sock);
    WSACleanup();
    system("pause");
    return 0;
    
}
