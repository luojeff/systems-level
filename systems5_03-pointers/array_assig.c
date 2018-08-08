#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));

  int i, arr[10], arr2[10];

  for(i=0; i<10; i++){
    arr[i] = rand();
    if(i == 9)
      arr[i] = 0;
  }

  for(i=0; i<10; i++){
    printf("arr[%d]: %d\n", i, arr[i]);
  }
  
  printf("\n");
  
  int *ip = &arr[0], *ip2 = &arr2[9];
  
  for(i=0; i<10; i++){
    *(ip2-i) = *(ip+i);
  }

  for(i=0; i<10; i++){
    printf("arr2[%d]: %d\n", i, *(arr2+i));
  }
  
  return 0;
}
