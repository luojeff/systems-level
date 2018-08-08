#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(){
  int f, fds[2], fds2[2];
  int receive, send;

  pipe(fds);
  pipe(fds2);
  
  if((f = fork()) > 0){
    close(fds[READ]);
    send = 42;
    write(fds[WRITE], &send, sizeof(send)); // (1)
    printf("Parent sends %d\n", send);

    close(fds2[WRITE]);
    read(fds2[READ], &receive, sizeof(receive)); // (4)
    printf("Parent receives %d\n", receive);
  } else if (f == 0) {
    close(fds[WRITE]);
    read(fds[READ], &receive, sizeof(receive)); // (2)
    printf("Child receives %d\n", receive);

    printf("Child operating on %d\n", receive);
    send = receive * 2 - 20;

    close(fds2[READ]);
    write(fds2[WRITE], &send, sizeof(send)); // (3)
    printf("Child sends %d\n", send);
  } else {
    printf("Fork failed!\n");
  }    

  return 0;
}
