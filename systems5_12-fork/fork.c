#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
  printf("Hi I'm a parent! My name is %d\n", getpid());
  
  pid_t f = fork();
  
  if (f > 0) {
    f = fork();
  }
  
  if (f == 0) {
    srand(getpid());
    int secs = rand() % 16 + 5;
    printf("Child PID: %d. This child will sleep for %d seconds\n", getpid(), secs);
    sleep(secs);
    printf("Child %d finished!\n", getpid());
    return secs;
  } else {        
    int status, child_pid = wait(&status);
    printf("Child with PID %d was asleep for %d seconds\n", child_pid, WEXITSTATUS(status));
    printf("Parent process %d is completed\n", getpid());
  }
  
  return 0;
}
