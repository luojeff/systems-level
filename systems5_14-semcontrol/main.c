#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <string.h>

#define SEM_KEY 12345

void print_error(){
  printf("Error: %s\n", strerror(errno));
}

int main(int argc, char *argv[]) {
  int sem_id, sem_val;
  char *command = argv[1];
  
  if(!strcmp(command, "-c")) {

    /* Create semaphore */
    if(argc < 3) {
      printf("Function takes additional parameters\n");
    } else {
      sem_val = atoi(argv[2]);

      if((sem_id = semget(SEM_KEY, 1, IPC_CREAT | IPC_EXCL | 0600)) < 0) {
	print_error();
      } else {
	semctl(sem_id, 0, SETVAL, sem_val);
	printf("Semaphore created: %d\n", sem_id);
	printf("Value set: %d\n", sem_val);
      }
    }
  } else if(!strcmp(command, "-v")) {
   
    if((sem_id = semget(SEM_KEY, 0, 0600)) < 0) {
      print_error();
    } else {

      /* Get value */  
      sem_val = semctl(sem_id, 0, GETVAL);
      if(sem_val == -1)
	print_error();
      else
	printf("Semaphore value: %d\n", sem_val);
    }
  } else if(!strcmp(command, "-r")) {

    if((sem_id = semget(SEM_KEY, 0, 0600)) < 0) {
      print_error();
    } else {

      /* Remove semaphore */
      if(semctl(sem_id, 1, IPC_RMID) < 0)
	print_error();
      else {
	printf("Semaphore removed\n");
      }
    }
  }
  
  return 0;
}
