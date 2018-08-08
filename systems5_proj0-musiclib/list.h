struct song_node {
  char name[256];
  char artist[256];
  struct song_node *next;
};


// "Slot" functions
struct song_node *insert_front(struct song_node *, char *, char*);
struct song_node *insert_song(struct song_node *, char *, char *);
struct song_node *insert_song_special(struct song_node **, char *, char *); // not tested in main function because we're using insert_song instead
struct song_node *find_song(struct song_node *, char *, char *);
struct song_node *find_song_artist(struct song_node *, char *);
struct song_node *get_random_song(struct song_node *);
struct song_node *remove_song(struct song_node *, struct song_node *);
struct song_node *free_list(struct song_node *);

void print_list(struct song_node *);
void print_song(struct song_node *);
// char *ret_info(struct song_node *);


// Library functions
struct song_node *search_song_node(struct song_node *[], char *, char *);
struct song_node *search_song_node_artist(struct song_node *[], char *);

void add_song(struct song_node *[], char *, char *);
void print_slot(struct song_node *[], char);
void print_artist_songs(struct song_node *);
void print_library(struct song_node *[]);
void print_random_songs(struct song_node *[]);
void delete_song(struct song_node *[], struct song_node *);
void delete_all_nodes(struct song_node *[]);
