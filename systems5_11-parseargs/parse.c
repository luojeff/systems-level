#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char **parse_args(char *);
int get_num_phrases(char *);

int main(){
  char inputs[] = "ls -l -t -r";
  
  char **args = parse_args(inputs);
  execvp(args[0], args);

  // no need to free allocated memory since execvp replaces process and reclaims the memory
}

int get_num_phrases(char *s){
  char valid_phrase = 0;
  int i, num_phrases = 0;
  for(i=0; i<strlen(s); i++){
    if(s[i] == ' ' && valid_phrase) {
      num_phrases++;
      valid_phrase = 0;
    } else if (s[i] != ' '){
      valid_phrase = 1;
    }
  }

  if(s[strlen(s)-1] != ' ')
    num_phrases++; // account for last phrase

  return num_phrases;
}

char **parse_args(char *line){
  int i=0;
  char *curr_arg = NULL;
  char **ret_args = (char **)malloc(sizeof(char *) * (get_num_phrases(line)+1));
  
  while(curr_arg = strsep(&line, " ")){
    ret_args[i] = (char *)malloc(strlen(curr_arg)+1);
    strcpy(ret_args[i], curr_arg);
    i++;
  }

  ret_args[i] = NULL;

  return ret_args;
}
