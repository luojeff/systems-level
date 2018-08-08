#include <stdio.h>
#include <string.h>
#include "ctrings.h"

int main() {
  char *s = "goodbye";
  char s1[32], s2[32] = "computer", s6[32] = "computer";
  char *s3 = "goodbye", *s4 = "friends", *s5 = "goodies";

  printf("\n--- Initial values --- \n");
  printf("s is [%s]\n", s);
  printf("s1 is [%s]\n", s1);
  printf("s2 is [%s]\n", s2);
  printf("s3 is [%s]\n", s3);
  printf("s4 is [%s]\n", s4);
  printf("s5 is [%s]\n", s5);
  printf("s6 is [%s]\n\n", s6);
  
  printf("--- Testing mystrlen(char*) ---\n");  
  printf("mystrlen(s): %d\n", mystrlen(s));
  printf("strlen(s): %lu\n\n", strlen(s));
  
  printf("--- Testing mystrcopy(char*, char*) ---\n");  

  printf("s1 after mystrcpy(s1, s): [%s]\n",   mystrcpy(s1, s));
  memset(&s1[0], 0, sizeof(s1)); // CLEARS array s1  
  strcpy(s1, s);
  printf("s1 after strcpy(s1, s): [%s]\n\n", s1);
  
  printf("--- Testing mystrncat(char*, char*, int) ---\n");  
 
  printf("s2 after mystrncat(s2, s, 4): [%s]\n",  mystrncat(s2, s, 4));//s2
    
  strncat(s6, s, 4);
  printf("s6 after strncat(s6, s, 4): [%s]\n\n", s6);

  printf("--- Testing mystrcmp(char*, char*) ---\n");  
  printf("Comparing [%s] and [%s] using mystrcmp: %d\n", s3, s, mystrcmp(s3, s));  
  printf("Comparing [%s] and [%s] using mystrcmp: %d\n", s4, s, mystrcmp(s4, s));  
  printf("Comparing [%s] and [%s] using mystrcmp: %d\n", s5, s, mystrcmp(s5, s));
  printf("Comparing [%s] and [%s] using strcmp: %d\n", s3, s, strcmp(s3, s));  
  printf("Comparing [%s] and [%s] using strcmp: %d\n", s4, s, strcmp(s4, s));  
  printf("Comparing [%s] and [%s] using strcmp: %d\n\n", s5, s, strcmp(s5, s));

  printf("--- Testing mystrchr(char*, char) ---\n");
  char c = 'o', c1 = 'k';
  printf("Substring from '%c' of \"%s\" is \"%s\"\n", c, s, mystrchr(s, c));
  printf("Substring from '%c' of \"%s\" is \"%s\"\n", c1, s, mystrchr(s, c1));
  printf("Address of pointer returned by mystrchr(s, c): %p\n", mystrchr(s, c));
  printf("Substring from '%c' of \"%s\" using standard is \"%s\"\n", c, s, strchr(s, c));
  printf("Substring from '%c' of \"%s\" using standard is \"%s\"\n", c1, s, strchr(s, c1));
  printf("Address of pointer returned by strchr(s, c): %p\n", strchr(s, c));
}
