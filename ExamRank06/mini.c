#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define ARGS "Wrong number of arguments\n"
#define FATAL "Fatal error\n"
#define BUFF 200000
#define PORTS 65000

int maxfd, sockfd, id = 0;
int clien_id_arr[PORTS];
char msg_buff[BUFF + 100];
fd_set rset, wset, aset;

void error(char *msg)
{
  if (sockfd > 2)
    close(sockfd);
  write(2, msg, strlen(msg));
  exit(1);
}

void replyToAll(int connfd)
{
  for (int fd = 2; fd <= maxfd; fd++;)
  {
    if ( fd != connfd && FD_ISSET(fd, &wset))
    {
      if (send(fd, msg_buff, strlen(msg_buff), 0) < 0)
        error(FATAL);
    }
  }
}

int main(int ac , char **av)
{
  int connfd;
  socklen_t len;
  struct sockaddr_in servaddr, cliaddr;

  if (ac != 2)
    error(ARGS);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd = -1)
    error(FATAL);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(2130706433);
  servaddr.sin_port = htons(atoi(av[1]));

  return (0);
}
