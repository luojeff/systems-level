#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

unsigned int get_random(int);

int main() {
  unsigned int rand_nums[10], rand_nums_compare[10];  
  
  printf("\nOpening file '/dev/random'... \n");
  int rand_fd = open("/dev/random", O_RDONLY);
  if (rand_fd == -1){
    printf("Status: %s\n", strerror(errno));
  }
  
  int i;
  printf("\n ===== First Array ===== \n");
  for(i=0; i<10; i++)
    rand_nums[i] = get_random(rand_fd);
  for(i=0; i<10; i++)
    printf("random %d: %u\n", i, rand_nums[i]);
  
  close(rand_fd);
  
  printf("\nOpening/creating file 'data' for writing... \n");
  int write_data = open("data", O_CREAT | O_WRONLY, 0644);
  if (write_data == -1){
     printf("Status: %s\n", strerror(errno));
  }

  int bytes_written, bytes_read;

  /* Write to data file */
  bytes_written = write(write_data, rand_nums, sizeof(rand_nums));
  printf("Bytes written to data file: %d\n", bytes_written);

  printf("\nOpening file 'data' for reading... \n");
  int read_data = open("data", O_RDONLY, 0644);
  if (read_data == -1){
    printf("Status: %s\n", strerror(errno));
  }
  
  /* Read from data file to new array */
  bytes_read = read(read_data, rand_nums_compare, sizeof(rand_nums_compare));
  printf("Bytes read to new array: %d\n", bytes_read);
  
  /* Print out new array */
  printf("\n ===== Second Array ===== \n");
  for(i=0; i<10; i++)
    printf("random %d: %u\n", i, rand_nums_compare[i]);

  close(write_data);
  close(read_data);  
}

/* Takes in file descriptor (to /dev/random) and returns a
   random number corresponding to the number of bytes */
unsigned int get_random(int rand_fd){
  unsigned int *buffer = (unsigned int *)malloc(sizeof(unsigned int));
  read(rand_fd, buffer, sizeof(unsigned int));
  unsigned int rand_num = *buffer;
  free(buffer);
  return rand_num;
}
