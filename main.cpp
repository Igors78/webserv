#include "webserv.hpp"

int main()
{
	/* Create a socket (IPv4, TCP) */
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		std::cout << "Failed to create a socket. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}

	/* Listen to port 9999 on any address */
	sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	sockaddr.sin_port = htons(9999);

	if (bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0)
	{
		std::cout << "Failed to bind to port 9999. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}

	/* Start listening.
	** Hold at most AF_MAX connections in the queue 
	*/
	if (listen(sockfd, AF_MAX) < 0)
	{
		std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);	
	}

	/* Grab a connection from the queue */
	size_t addrlen = sizeof(sockaddr);
	int connection = accept(sockfd, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
	if (connection < 0)
	{
		std::cout << "Failed to grab connection. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}

	/* Read from the connection */
	char buffer[100];
	size_t bytesRead = read(connection, buffer, 100);
	std::cout << "The message was made up with " << bytesRead << "bytes and it was: " << buffer;

	/* Send a message to the connection */
	std::string response = "Good talking to you\n";
	send(connection, response.c_str(), response.size(), 0);

	/* Close the connections */
	close(connection);
	close(sockfd);
}
