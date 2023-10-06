#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

int	main() {
	int					serverFd, connectedFd, maxFds, i;
	char				buffer[4096];
	socklen_t			len;
	struct sockaddr_in	servaddr, cli;
	fd_set				fds, writefds, readfds;

	serverFd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverFd == -1)
		return (printf("Error: socket creation failed.\n"), 1);

	maxFds = serverFd;
	FD_ZERO(&fds);
	FD_SET(serverFd, &fds);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(6969);

	if (bind(serverFd, (const struct sockaddr *)&servaddr, sizeof(servaddr)))
		return (printf("Error: bind socket failed.\n"), 1);

	if (listen(serverFd, servaddr.sin_port) != 0)
		return (printf("Error: cannot listen.\n"), 1);

	bzero(&buffer, sizeof(buffer));
	while (1) {
		writefds = readfds = fds;
		if (select(maxFds + 1, &writefds, &readfds, NULL, NULL) == -1)
			continue ;

		for (i = 0; i <= maxFds; i++) {
			if (FD_ISSET(i, &writefds) && i == serverFd) {
				connectedFd = accept(serverFd, (struct sockaddr *)&cli, &len);
				if (connectedFd == -1)
					continue ;

				maxFds = (connectedFd > maxFds) ? connectedFd : maxFds;
				FD_SET(connectedFd, &fds);
			}
			else if (FD_ISSET(i, &writefds) && i != serverFd) {
				int res = recv(connectedFd, buffer, sizeof(buffer), 0);
				if (res <= 0) {
					FD_CLR(i, &fds);
					close(i);
					break ;
				}
				printf("%s\n", buffer);
				bzero(&buffer, strlen(buffer));
			}
		}
	}
	return 0;
}
