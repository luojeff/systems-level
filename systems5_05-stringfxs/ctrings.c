#include <stdio.h>
#include <string.h>
#include "ctrings.h"

//takes in char pointer and returns length by counting chars
// up to NULL
int mystrlen(char *s){
  int i = 0;
  while(*s++){i++;}
  return i;
}

//takes in two char pointers and copies chars of source to dest
// up to and including NULL in source
char * mystrcpy( char *dest, char *source ){
  char *dest2 = dest;//saves dest's value since it will be changed
  while(*dest++ = *source++){}//sets chars of dest to chars of source up to NULL
  return dest2;//returns where dest originaly pointed
}

//takes in two char pointers and an int.
//replaces dest's NULL and beyond with n of source's chars
//returns where dest pointed at first
char * mystrncat( char *dest, char *source, int n){
  int i=0, count=0;

  while(*dest){
    dest++;
    count++;
  }//where dest points to its NULL
  
  while(i < n && *source){
    *dest++ = *(source+i++);
  }//copies source's chars 
  
  return dest - i - count; //where dest originaly pointed
}

//mystrcmp takes two char poitners and returns a:
// positive value if s1>s2
// 0 if s1=s2
// negative value if s1<s2
int mystrcmp( char *s1, char *s2 ){
  while(*s1 == *s2 && *s1 > 0 && *s2 > 0){
    s1++;
    s2++;
  }//moves up to first character at which s1 and s2 differ
  //(NULL for both if s1==s2)
  
  return *s1 - *s2;//difference in characters at difference
}

//mystrchr takes a char pointer and a char and returns
// string starting from where c is located(NULL if it isn't there)
char * mystrchr( char *s, char c ){  
  while(*s != c && *s != 0){
    s++;
  }
  
  if(!*s)
    return 0;
  return s;  
}
