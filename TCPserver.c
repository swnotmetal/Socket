#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    char server_message[512] = "Server reached.";

    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9666);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket,(struct sockaddr *) &server_addr, sizeof(server_addr));
    
    listen(server_socket, 3);

    int clinet_socket;
    clinet_socket = accept(server_socket, NULL, NULL);

    send(clinet_socket, server_message, sizeof(server_message), 0);

    close(server_socket);

    return 0;
}