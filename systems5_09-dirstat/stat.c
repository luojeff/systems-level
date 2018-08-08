#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_size(off_t);
void print_permissions(mode_t);
char * get_binary(int);

int main(){
  int err;
  struct stat meta;
  char target_file[] = "sample";

  err = stat(target_file, &meta);
  
  printf("File details for %s\n", target_file);
  printf("Time of access: %s\n", ctime(&(meta.st_atime)) );

  print_size(meta.st_size);
  print_permissions(meta.st_mode);
}

void print_size(off_t size){
  char *units[4] = {"B", "KB", "MB", "GB"};
  int count = 0, remainder = 0;

  while(size / 1000){
    remainder = size % 1000;
    size /=  1000;
    count++;
  }

  if((remainder / 100) >= 5)
    size++;

  printf("Size of file: %d%s\n", (int)size, units[count]);
}

void print_permissions(mode_t perm){
  
  // 511: 111 111 111
  perm = perm & 511;
  
  char binary[10];
  char *bin = get_binary(perm);
  strcpy(binary, bin);

  char modes[3] = "rwx";
  printf("Permissions: ");
  int i;
  for(i=0; i<9; i++){
    if(binary[i]-1){
      printf("%c", modes[i % 3]);
    } else {
      printf("-");
    }
  }

  printf("\n");
  free(bin);
}

char * get_binary(int val){
  char *ptr = (char *)malloc(10);

  int i;
  for(i=0; i<9; i++){
    ptr[8-i] = (val % 2) + 1;
    val /= 2;
  }

  ptr[9] = 0;

  return ptr;
}
