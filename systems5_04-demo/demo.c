#include <stdio.h>
#include <string.h>

int main(){

  /* strcpy 
     char* strcpy(char *dest, const char *src);
     - Copies a string pointed to by 'src' into a destination, then returns a pointer to a destination string

     Note: 
     - The NULL character is included
     - 'src' is a pointer to immutable char data ('const char')
     - Char sequence to be copied should be NULL-terminated.
     - Destination (dest) should be large enough, otherwise the result may be unpredictable
  */

  char *tocopy_1 = "systems"; /* string literals terminate with NULL */
  char *tocopy_2 = "key";
  
  char dest_1[10];
  char dest_2[] = "placeholder";
      
  strcpy(dest_1, tocopy_1);
  printf("String in dest_1: %s\n", dest_1);

  strcpy(dest_2, tocopy_2);
  printf("String in dest_2: %s\n", dest_2);
  
  /* strncpy
     char *strncpy(char *dest, const char *src, size_t n)
     - Copies n chars from the string pointed to by src into a destination.

     Note:
     - strncpy does not add null terminate character after going through n chars
     - If n is greater than the length of src, every following character is replaced
     by a null terminate character.     
  */

  char dest_3[] = "long placeholder";
  char dest_4[5];  

  strncpy(dest_3, tocopy_1, 12); // should copy entire 'tocopy_1.' NULLs follow until 12 chars total have been written
  strncpy(dest_4, tocopy_1, 3); // should only copy 'sys'
  dest_4[3] = 0;

  printf("String in dest_3: %s\n", dest_3);
  printf("String in dest_4: %s\n", dest_4);
  
  return 0;
}
