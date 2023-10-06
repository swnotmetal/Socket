#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    // create a socket.
    int local_network_socket;
    local_network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // address for the socket.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons (9666); /* Registered Ports (1024-49151):Available for applications, but they are not standardized in the same way as well-known ports. 
    They are assigned by the Internet Assigned Numbers Authority (IANA) to the requesting organization.*/
    server_addr.sin_addr.s_addr = INADDR_ANY; // or 0.0.0.0 if local

    int connection_status = connect(local_network_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    
    // check if everything is ok with the connection
    if (connection_status == -1)
    {    
        printf("Error in connection\n\n");
    }
    char    server_resp[512];
    recv(local_network_socket, &server_resp, sizeof(server_resp), 0);

    //print out the response
    printf("the server sent the data: %s", server_resp);

    close(local_network_socket);

    return 0;
}
