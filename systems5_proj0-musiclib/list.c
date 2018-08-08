#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
  Don't forget:
  -> Account for edge cases (search not found, indexing, etc.)
*/

/* === Slot Functions === */

/* Prints contents of list pointed to by sp */
void print_list(struct song_node *sp){
  /* Make sure pointer to struct song_node is not null */
  printf("| ");
  while(sp){
    printf("\"%s\" by ", sp->name);
    printf("\"%s\"", sp->artist);
    
    if(sp = sp->next){
      printf(" | ");
    }
  }
  printf(" |\n");
}

void print_song(struct song_node *sp){
  if(sp)
    printf("| \"%s\" by \"%s\" |\n", sp->name, sp->artist);
  else
    printf("No valid song to print!!!\n");
}

char *ret_info(struct song_node *sp){
  char *s = (char *)malloc(512 * sizeof(char));
  strcat(s, sp->name);
  strcat(s, " by ");
  strcat(s, sp->artist);
  strcat(s, "\n");
  
  return s;
}

struct song_node *insert_front(struct song_node *sp, char *name, char *artist){
  
  /* Allocates memory in the heap */
  struct song_node *to_add = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(to_add->name, name);
  strcpy(to_add->artist, artist);
  to_add->next = sp;

  return to_add;
}

struct song_node *insert_song(struct song_node *front, char *name, char *artist) {
  int beginning; // explained later in this function
  
  // Allocate memory to the heap   
  struct song_node *tmp = front, *to_add = (struct song_node *)malloc(sizeof(struct song_node) * 1);
  strcpy(to_add->name, name);
  strcpy(to_add->artist, artist);
  to_add->next = NULL; // so as not to leave a dangling pointer

  // printf("Address of tmp: %p\n", tmp);

  // test if to_add belongs at the beginning of the list
  if(tmp){
    beginning = strcmp(to_add->artist, tmp->artist);
  } else {
    // if tmp points to NULL address; if list is initially empty (excluding dummy pointer)
    beginning = -1;
  }

  if (beginning < 0) {
    // to_add should be inserted at beginning of list
    to_add->next = tmp;
    return to_add; // this is the new front of the list
  }
  if (beginning == 0) {
    /*
     * to_add has the same artist as the first song in the list does.
     * Compare the names of the songs.
     */
    beginning = strcmp(to_add->name, tmp->name);
    if (beginning < 0) {
      to_add->next = tmp;
      return to_add;
    }
    if (beginning == 0) {
      printf("The song \'%s\' by \'%s\' already exists in this library.\n", to_add->name, to_add->artist);
      free(to_add);
      return front;
    } // else leave tmp where it is for now
    
  } // end if statement

  // Walk tmp up to proper spot in alphabet according to artist
  while (tmp->next && strcmp(to_add->artist, tmp->next->artist) > 0)
    tmp = tmp->next;

  if (!(tmp->next)) { // append to_add to the end of the list
    tmp->next = to_add;
    return front;
  }

  // test if there are any other songs with the same artist as to_add  
  beginning = strcmp(to_add->artist, tmp->next->artist);

  if (beginning < 0) {
    /*
     * There are no other songs by the same artist; the song node should be
     * inserted between the two surrounding artists
     */
    to_add->next = tmp->next;
    tmp->next = to_add;
  } else {
    while (tmp->next && strcmp(to_add->name, tmp->next->name) > 0) {
      // Walk tmp up to proper spot in alphabet according to song name.
      tmp = tmp->next;
    }

    if(!(tmp->next)){
      to_add->next = tmp->next;
      tmp->next = to_add;      
    } else if (strcmp(to_add->name, tmp->next->name) == 0) {
      printf("The song \'%s\' by \'%s\' already exists in this library.\n", to_add->name, to_add->artist);
      free(to_add);
    } else {
      // this is the spot where to_add should be inserted.
      to_add->next = tmp->next;
      tmp->next = to_add;
    }
  }

  return front;
  
} // end struct song_node *insert_song(struct song_node *, struct song node)


struct song_node *insert_song_special(struct song_node **front, char *name, char *artist) {
  int beginning;
  
  struct song_node *tmp = *front;
  struct song_node *to_add = (struct song_node *)malloc(sizeof(struct song_node) * 1);
  strcpy(to_add->name, name);
  strcpy(to_add->artist, artist);
  to_add->next = NULL;
  
  if(tmp)
    beginning = strcmp(to_add->artist, tmp->artist);
  else
    beginning = -1;
  

  if (beginning < 0) {    
    to_add->next = tmp;
    *front = to_add;
    return to_add;
  } else if (beginning == 0) {
    beginning = strcmp(to_add->name, tmp->name);
    if (beginning < 0) {
      to_add->next = tmp;
      *front = to_add;
      return to_add;
    }
    if (beginning == 0) {
      printf("The song \'%s\' by \'%s\' already exists in this library.\n", to_add->name, to_add->artist);
      free(to_add);
      return *front;
    }
  }
  
  while (tmp->next && strcmp(to_add->artist, tmp->next->artist) > 0)
    tmp = tmp->next;

  if (!(tmp->next)) {
    tmp->next = to_add;
    return *front;
  }
  
  if (tmp->next)
    beginning = strcmp(to_add->artist, tmp->next->artist);
  else
    beginning = -1;

  if (beginning < 0) {
    to_add->next = tmp->next;
    tmp->next = to_add;
  } else {
    while (tmp->next && strcmp(to_add->name, tmp->next->name) > 0)
      tmp = tmp->next;
    if (strcmp(to_add->name, tmp->next->name) == 0) {
      printf("The song \'%s\' by \'%s\' already exists in this library.\n", to_add->name, to_add->artist);
      free(to_add);
    } else {      
      to_add->next = tmp->next;
      tmp->next = to_add;
    }
  }

  return *front;
}


/* Frees up all nodes */
struct song_node *free_list(struct song_node *sp){
  while(sp){
    struct song_node *old = sp;
    sp = sp->next;
    printf("\"%s\" by \"%s\" deleted!\n", old->name, old->artist);
    free(old);
    old = NULL;
  }

  return sp;
}

struct song_node *remove_song(struct song_node *sp, struct song_node *rmnode) {
  struct song_node *front = sp;

  if(!rmnode){
    printf("Song could not be deleted!\n");
    return front;
  }
  
  if (sp == rmnode) {
    sp = sp->next;
    printf("Removing \"%s\" by \"%s\"\n", rmnode->name, rmnode->artist);
    free(front);    
    return sp;
  }

  // Increment sp up to the node directly before rmnode
  while(sp && ((sp->next) != rmnode)) {
    sp = sp->next;  
  }
  
  struct song_node *to_remove = sp->next;
  printf("Removing \"%s\" by \"%s\"\n", rmnode->name, rmnode->artist);
  sp->next = to_remove->next;
  free(to_remove);
  
  return front;
}

struct song_node *get_random_song(struct song_node *sp){
  int rand_index = 0, size = 0;
  struct song_node *tmp = sp, *front = sp;
  
  while(tmp){
    tmp = tmp->next;
    size++;
  }  

  if(size){
    rand_index = rand() % size;
  } else {
    return 0;
  }

  while(rand_index > 0){
    if(sp->next)
      sp = sp->next;
    else
      sp = front;
    rand_index--;
  }
  
  return sp;
}

struct song_node *find_song(struct song_node *sp, char *song_name, char *artist_name){
  struct song_node *front = sp;
  printf("Searching for \"%s\" by \"%s\"\n", song_name, artist_name);

  while(front){
    if(!(strcmp(front->name, song_name) || strcmp(front->artist, artist_name)))
      return front;
    else
      front = front->next;
  }

  printf("Song '%s' by '%s' not found!\n", song_name, artist_name);
  return 0;
}

struct song_node *find_song_artist(struct song_node *sp, char *artist_name){
  printf("Searching for artist \"%s\"\n", artist_name);
  
  while(sp){
    if(!strcmp(sp->artist, artist_name))
      return sp;
    else
      sp = sp->next;
  }

  printf("Song(s) by '%s' not found!\n", artist_name);
  return sp;
}

/* === Library Functions === */

void add_song(struct song_node *lib[], char *name, char *artist){
  //insert_song_special(&(lib[artist[0] - 'a']), name, artist);

  struct song_node *slot = lib[artist[0] - 'a'];
  
  lib[artist[0] - 'a'] = insert_song(slot, name, artist);
}

struct song_node *search_song_node(struct song_node *lib[], char *name, char *artist){
  struct song_node *slot = lib[artist[0] - 'a'];
  return find_song(slot, name, artist);
}

struct song_node *search_song_node_artist(struct song_node *lib[], char *artist_name){
  struct song_node *slot = lib[artist_name[0] - 'a'];  
  return find_song_artist(slot, artist_name);
}

void print_slot(struct song_node *lib[], char c){
  printf("%c: ", c);
  print_list(lib[c-'a']);
}

void print_artist_songs(struct song_node *sp){
  struct song_node *tmp = sp;
  
  printf("| ");
  while(tmp){
    if(!strcmp(tmp->artist, sp->artist)){
      printf("\"%s\" by \"%s\" | ", tmp->name, tmp->artist);
    } else {
      printf("\n");
      return;
    }
    if(tmp->next){      
      tmp = tmp->next;
    } else {      
      printf(" |\n");
      tmp = NULL;
    }
  }

  
}

void print_library(struct song_node *lib[]){
  int i;
  for(i=0; i<26; i++){
    if(lib[i]) {
      printf("%c list: ", i+97);
      print_list(lib[i]);
    }
  }
  printf("\n");
}

void print_random_songs(struct song_node *lib[]){
  //int i = 0;
  //struct song_node * dummy;

  // a separate array to store the number of nodes in each linkedlist within lib
  //int sizes[27] = {0};

  //int libsize = 0; // calculates the size

  /*
    printf("|");
    for (i; i < 26; i++) {
    printf("%d ", arr[i]);
    }
    printf("|");
    i = 0;
  */
  
  //for (i; i < 26; i++) {
  /*
    dummy = lib[i];
    while (dummy) {
    arr[i]++;
    dummy = dummy->next;
    }
  */
  /*
    arr[i] = list_size(lib[i])
    }
  */

  struct song_node *front = NULL;

  printf("| ");
  for(int i=0; i<26; i++){
    
    if(front = lib[i]) {
      
      while(front){
	if(rand() % 2)
	  printf("\"%s\" by \"%s\" | ", front->name, front->artist);
	front = front->next;	
      }
    }
  }
  printf("\n");
}

void delete_song(struct song_node *lib[], struct song_node *rmnode){
  struct song_node *slot = lib[(rmnode->artist)[0] - 'a'];
  
  lib[(rmnode->artist)[0] - 'a'] = remove_song(slot, rmnode);
}

void delete_all_nodes(struct song_node *lib[]){
  int i;
  for(i=0; i<26; i++){
    free_list(lib[i]);
    lib[i] = NULL;
  }
}
