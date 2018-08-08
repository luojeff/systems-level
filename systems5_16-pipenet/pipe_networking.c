#include "pipe_networking.h"
#include <sys/types.h>
#include <string.h>

#define WKP "wkp"

/*=========================
  server_handshake
  args: int * to_client

  Performs the server side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {  
  char client_response[256];

  mkfifo(WKP, 0644);

  int fdWKP  = open(WKP, O_RDONLY);//waits for client to open WKP
  remove(WKP);//client connected by now  
  read(fdWKP, client_response, sizeof(client_response));
  printf("Recieved message from client: %s\n", client_response);

  int fdPP = open(client_response, O_WRONLY);  
  char stc_confirm[] = "server confirms";
  write(fdPP, stc_confirm, sizeof(stc_confirm));
  printf("Sending response to client: %s\n", stc_confirm);

  read(fdWKP, client_response, sizeof(client_response));

  if(strcmp(client_response, "client confirms") != 0){
    printf("Client did not send correct message back! \n");
    return 0;
  } else
    printf("Received response from client: %s\n", client_response);

  *to_client = fdPP;//downstream pipe  
  return fdWKP;//file descriptor of upstream pipe
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  char contents[256];
  char priv_pipe[] = "0396alf";

  mkfifo(priv_pipe, 0644);

  int fdWKP = open(WKP, O_WRONLY);//server is on other end waiting for client
  write(fdWKP, priv_pipe, strlen(priv_pipe));
  printf("Sent private pipe %s to server\n", priv_pipe);

  int fdPP = open(priv_pipe, O_RDONLY);//waits for server to open PP  
  read(fdPP, contents, sizeof(char)*256);//waits for response
  
  if(strcmp(contents, "server confirms") != 0){ //enters only if response is wrong
    printf("Wrong response from server\n");
    return 0;
  } else
    printf("Recieved confirmation from server: %s\n", contents);

  remove(priv_pipe);

  char cts_confirm[] = "client confirms";
  write(fdWKP, cts_confirm, sizeof(cts_confirm));
  printf("Sending response to server: %s\n", cts_confirm);

  *to_server = fdWKP;//upstream pipe
  return fdPP;//returns downstream pipe file descritor
}

