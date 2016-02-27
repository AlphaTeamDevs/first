// Client

#include <iostream>
#include <windows.h>
#include <winsock2.h>

using namespace std;

int main()
{
    
    cout << "Client: " << endl;
    
    char ip[17];
    u_short port;
    char message[MAX_PATH];
    
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
                           
        cout << "Can't load WSA library." << endl;
                           
    }
    else
    {
        
        cout << "WSA library load complite" << endl; 
        
    }
    
    SOCKET send_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(send_sock == SOCKET_ERROR)
    {
               
        cout << "Can't create socket." << endl;
               
    }
    else
    {
        
        cout << "Socket create complite." << endl;
        
    }
    
    SOCKADDR_IN send_sock;    
    
    Client.sin_family = AF_INET;
    Client.sin_port = htons(port);
    Client.sin_addr.s_addr = inet_addr(ip);
    
    while(1)
    {
               
        if(connect(send_sock, (SOCKADDR*)&Client, sizeof(Client)))
        {
                            
            cout << "Complite connect to server." << endl;
            
            send(send_sock, "Message from client: You complite connect to Client.", MAX_PATH, 0);
            
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
