#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){
  switch(signo) {
  case SIGINT:
    printf("Process ended due to SIGINT\n");
    
    unsigned fd = open("status", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char s[] = "Process ended due to SIGINT\n";
    write(fd, s, sizeof(s));    
    close(fd);
    
    exit(0);
  case SIGUSR1:
    printf("Parent PID: %d\n", getppid());
    break;
  }
}

int main() {

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1) {
    printf("PID: %d\n", getpid());    
    sleep(1);
  }
  
  return 0;
}
