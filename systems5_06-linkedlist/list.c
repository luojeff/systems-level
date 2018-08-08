#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Prints contents of list pointed to by sp */
void print_list(struct node *sp){
  printf("[ ");

  /* Make sure pointer to struct node is not null */
  while(sp){
    printf("%d ", sp->i);
    sp = sp->next;
  }

  printf("]\n");
}

/* Inserts node into front of list */
struct node *insert_front(struct node *sp, int val){
	
  /* Allocates memory in the heap */
  struct node *to_add = (struct node *)malloc(sizeof(struct node) * 1);
  to_add->i = val;
  to_add->next = sp;

  return to_add;
}

/* Frees up all nodes */
struct node *free_list(struct node *sp){
  while(sp != NULL){
    struct node *old = sp;
    sp = sp->next;
    free(old);
    old = NULL;
  }

  return sp;
}
