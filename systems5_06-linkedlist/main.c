#include <stdio.h>
#include "list.h"

int main() {

  /* Testing linked list program */
  struct node *test = NULL, *test2 = NULL;

  printf("\n--- Testing linked list program ---\n");

  printf("Contents of test: ");
  print_list(test);
  printf("Contents of test2: ");
  print_list(test2);

  printf("Added ");
  for(int i=0; i<20; i++){
    printf("%d ", i);
    test = insert_front(test, i);
  }
  printf("to test\n");

  printf("After adding nodes to test: ");
  print_list(test); // [ 6 24 18 27 ]
  test = free_list(test);
  printf("After freeing nodes in test: ");
  print_list(test); // [  ]  Empty list

  test2 = insert_front(test2, 100);
  test2 = insert_front(test2, 100);
  test2 = insert_front(test2, 100);
  test2 = insert_front(test2, 100);
  test2 = insert_front(test2, 100);

  printf("After adding nodes to test2: ");
  print_list(test2); // [ 100 100 100 100 100 ]
  test2 = free_list(test2);

  test2 = insert_front(test2, 50);
  test2 = insert_front(test2, 50);

  printf("After freeing and adding new nodes to test2: ");
  print_list(test2); // [ 50 50 ]
}
