#include "webserv.hpp"

int main()
{
	t_socket	server;

	/* Create a socket (IPv4, TCP) */
	if ((server.fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		std::cout << "Failed to create a socket. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}

	/* Listen to port SERVER_PORT on any address */
	ft_memset((unsigned char *)&server.addr, 0, sizeof(server.addr));
	server.addr.sin_family = AF_INET;
	server.addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server.addr.sin_port = htons(SERVER_PORT);

	if (bind(server.fd, (struct sockaddr *)&server.addr, sizeof(server.addr)) < 0)
	{
		std::cout << "Failed to bind to port 42. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}

	/* Start listening.
	** Hold at most AF_MAX connections in the queue 
	*/
	if (listen(server.fd, BACKLOG) < 0)
	{
		std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);	
	}

	/* Grab a connection from the queue */
	server.addrlen = sizeof(sockaddr);
	if ((server.connection = accept(server.fd, (struct sockaddr*)&server.addr, (socklen_t*)&server.addrlen)) < 0)
	{
		std::cout << "Failed to grab connection. errno: " << errno << std::endl;
		exit(EXIT_FAILURE);
	}

	/* Read from the connection */
	char buffer[10000];
	size_t bytesRead = read(server.connection, buffer, 10000);
	std::cout << "The message was made up with " << bytesRead << "bytes and it was: " << buffer;

	/* Send a message to the connection */
	std::string response = "Good talking to you\n";
	send(server.connection, response.c_str(), response.size(), 0);

	/* Close the connection */
	close(server.connection);
	close(server.fd);
}
