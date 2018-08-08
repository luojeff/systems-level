#include "pipe_networking.h"
#include <string.h>
#include <sys/sem.h>

char *rev_str(char*);

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  while(1){
    char response[256];

    printf("----------------\n");
    printf("Waiting for message from client...\n");
    read(from_client, response, sizeof(response)); //waits for response
    printf("Message received: %s\n", response); 
    
    printf("Modifying response...\n");
    char *modified = rev_str(response);

    printf("New response: %s\n", modified);

    printf("Sending modified text...\n");
    write(to_client, response, sizeof(response));
  }
}

char *rev_str(char *str){
  int a = strlen(str)-1;
  int b=0;

  char c;
  while(a > b){
    c = str[a];
    str[a]= str[b];
    str[b] = c;
    a--;
    b++;
  }
  return str;
}
