
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int socket_fd;
  struct sockaddr_in target;

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("Socket criado\n");

  target.sin_family = AF_INET;
  target.sin_port = htons(3000);
  inet_aton("127.0.0.1", &(target.sin_addr));
  printf("Tentando conectar\n");
  if (connect(socket_fd, (struct sockaddr*)&target, sizeof(target)) != 0) {
    printf("Problemas na conexao\n");
    return 0;
  }
  printf("Conectei ao servidor\n");

  /* Agora, meu socket funciona como um descritor de arquivo usual */
  write(socket_fd, "PING", 5);
  printf("Escrevi mensagem de ping!\n");
  close(socket_fd);
  return 0;
}
