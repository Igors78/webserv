/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:38:44 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/21 17:27:35 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# define SERVER_PORT	4242
# define BACKLOG		42

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h> // struct sockaddr_in
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <cerrno>

typedef struct s_socket {

public:

	int			fd;
	sockaddr_in	addr;
	size_t		addrlen;
	int			connection;
}	t_socket;

void	*ft_memset(void *s, int c, size_t n);

#endif