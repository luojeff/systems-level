#include "pipe_networking.h"

void *trim_string(char*, int);

int main() {
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );  

  /* Sends message to server, gets modified response back */
  while(1){
    char response[256];
    
    printf("----------------\n");    
    printf("Enter text: ");
    fgets(response, sizeof(response), stdin);

    trim_string(response, strlen(response)-1);    
    
    printf("Sending text to server...\n");
    write(to_server, response, sizeof(response));

    read(from_server, response, sizeof(response)); //waits for response
    printf("Received modified text: %s\n", response);
  }
}

void *trim_string(char *s, int size) {
  s[size] = '\0';
}
