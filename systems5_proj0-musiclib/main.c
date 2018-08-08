#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main(){
  srand(time(NULL)); 
  struct song_node *test = NULL;

  printf("\n ****************************************************** \n");
  printf(" *************** TESTING LIST FUNCTIONS *************** ");
  printf("\n ****************************************************** \n");
  
  //printf("\n =============== Testing insert_front() =============== \n");
  test = insert_front(test, "thriller", "the michael jackson");
  test = insert_front(test, "hey jude", "the beatles");
  test = insert_front(test, "help!", "the beatles");
  test = insert_front(test, "a song", "the an artist");

  //printf("\n =============== Testing insert_song() =============== \n");
  test = free_list(test);
  test = insert_song(test, "hey jude", "the beatles");
  test = insert_song(test, "thriller", "the michael jackson");
  test = insert_song(test, "a song", "the an artist");
  test = insert_song(test, "help!", "the beatles");
  test = insert_song(test, "butter", "the charlies");
  test = insert_song(test, "bz", "the charlies");
  test = insert_song(test, "aaa", "the aarons");
  test = insert_song(test, "rockstar", "post malone");
  test = insert_song(test, "flicker", "niall horan");

  printf("\n =============== Testing print_list() =============== \n");
  print_list(test);

  printf("\n =============== Testing remove_song() =============== \n");  
  test = remove_song(test, find_song(test, "hey jude", "the beatles"));
  test = remove_song(test, find_song(test, "rock the boat", "aaliyah"));
  test = remove_song(test, find_song(test, "aaa", "the aarons"));
  test = remove_song(test, find_song(test, "see you again", "wiz khalifa"));
  print_list(test);
  
  
  printf("\n =============== Testing get_random_song() =============== \n");
  print_song(get_random_song(test));
  print_song(get_random_song(test));
  print_song(get_random_song(test));
  print_song(get_random_song(test));

  printf("\n =============== Testing find_song() =============== \n");
  print_song(find_song(test, "thriller", "the michael jackson"));
  print_song(find_song(test, "hey jude", "the beatles"));
  print_song(find_song(test, "a song", "the an artist"));
  print_song(find_song(test, "flicker", "niall horan"));

  printf("\n =============== Testing find_song_artist() =============== \n");
  print_list(find_song_artist(test, "niall horan"));
  print_list(find_song_artist(test, "post malone"));
  print_list(find_song_artist(test, "the michael jackson"));
  print_list(find_song_artist(test, "the charlies"));

  printf("\n =============== Testing free_list() =============== \n");
  test = free_list(test);  
  printf("List after free_list():\n"); print_list(test);


  printf("\n\n ****************************************************** \n");
  printf(" ************* TESTING LIBRARY FUNCTIONS ************** ");
  printf("\n ****************************************************** \n\n");
  
  struct song_node *table[26];
  int i, tab_len = sizeof(table)/sizeof(struct song_node *);
  for(i=0; i<tab_len; i++){
    struct song_node *dummy_node = NULL;
    table[i] = dummy_node;
  }  

  //printf("\n =============== Testing add_song() =============== \n");
  add_song(table, "sky full of stars", "coldplay");
  add_song(table, "yellow", "coldplay");
  add_song(table, "viva la vida", "coldplay");
  add_song(table, "nightshift", "commodores");
  add_song(table, "beat it", "michael jackson");
  add_song(table, "paradise", "coldplay");  
  add_song(table, "nightshire", "commodores");
  add_song(table, "where the streets have no name", "u2");
  add_song(table, "drops of jupiter", "train");
  add_song(table, "two hearts", "phil collins");
  add_song(table, "take me home", "phil collins");
  add_song(table, "the candy man", "sammy davis jr");
  add_song(table, "billie jean", "michael jackson");
  add_song(table, "alpha", "commodores");
  add_song(table, "beanie", "commodores");
  

  printf("\n =============== Testing duplicate add =============== \n");
  add_song(table, "yellow", "coldplay"); // 'already exists' test case
  add_song(table, "two hearts", "phil collins");
  add_song(table, "alpha", "commodores");
  
  printf("\n =============== Testing print_library() =============== \n");
  print_library(table);
  
  printf("\n =============== Testing print_slot() =============== \n");
  print_slot(table, 'b');
  print_slot(table, 'c');
  print_slot(table, 's');

  printf("\n =============== Testing search_song_node() =============== \n");
  print_song(search_song_node(table, "yellow", "coldplay"));
  print_song(search_song_node(table, "two hearts", "phil collins"));
  print_song(search_song_node(table, "good song", "justin bieber"));

  printf("\n =============== Testing search_song_node_artist() =============== \n");
  print_artist_songs(search_song_node_artist(table, "train"));
  print_artist_songs(search_song_node_artist(table, "coldplay"));

  printf("\n =============== Testing delete_song() =============== \n");
  delete_song(table, search_song_node(table, "yellow", "coldplay"));
  delete_song(table, search_song_node(table, "two hearts", "phil collins"));
  
  print_artist_songs(search_song_node_artist(table, "coldplay"));

  printf("\n =============== Testing print_random_songs() =============== \n");
  print_random_songs(table);

  /* REMEMBER TO FREE THE LIBRARY */
  printf("\n =============== Testing delete_all_nodes() =============== \n");
  delete_all_nodes(table);

  printf("\n =============== Library after delete  =============== \n");
  print_library(table);
  
  // print_library(table); WON'T WORK SINCE POINTERS ARE IN SAME POSITION, BUT THE ADDRESSES ARE FREED!!!
  
  return 0;
}
