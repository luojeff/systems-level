# proj1-turtlez by Jasper Cheung Jeffrey Luo

## Features:
-	Forks and executes commands!
-	Parses multiple commands on one line through semicolons (;).
-	Stdin & stdout redirection allowed through < and >.
-	Piping (|) works!

## Attempted:
-	Feature to allow for multiple pipes and/or redirections in one command.

## Bugs:
-	Tokens in echo cannot contain semicolons when piped. This is
          due to the method in which parsing is implemented.
          e.g. this will not work -> $ echo "ls; pwd; exit" | ./target
-	Stdout redirection may occasionally add bash prompts as part of
          the output ("<shell>").
          
## Files & Function Headers:

### parse.c
Handles all line parsing functions.

```
/*======== char **parse_input() =========
Inputs:  char *line
          char* delimiter

Returns: Array of char pointers, with each char pointer being a token
of line separated by string delimiter. Separates string line by the 
string delimiter.
====================*/

/*======== char *trim_string() =========
Inputs: char *s
          int size
          
Returns: String representing first size characters of string s, trimming out
garbage values.

Returns the first size characters of string s. Terminating NULL is automatically
added to end of the returned string.
====================*/

/*======== char *trim_trailing() ==========
Inputs: char *s 
          char c 

Returns: String without char c's in the front and end. 

Trims characters c from beginning and end of string s. Stops in one direction when
a different character is encountered. Returned string does contain a terminating NULL.
====================*/

/*======== int count_occur() ==========
Inputs: char *s
          char *occ

Returns: An integer representing the number of times occ appear in string s

Counts occurrences of substring occ in string s. The number of tokens can be
found by adding 1 onto the return value.
====================*/
```

### main.c
Handles the forking and executing of commands

```
/*======== void print_error() ==========
Inputs: None

Returns: None

Prints error message sent to errno 
====================*/

/*======== int handle_general_commands() ==========
Inputs: char *command

Returns: -1 when error, or execvp runs

Reads in a string command and executes it. If it can't be executed,
an error message is printed out. Also handles commands that can't be
execvp'd directly. If "parent" command or fork fails, returns -1. 
If child fails, exits immediately.
====================*/

/*======== void redirect() ==========
Inputs: int base_fd
          int fd
          char *first
          char *second

Returns: None

Redirects output of command first to command second. 
File descriptor fd represents entry of command second. 
base_fd is the placeholdered file descriptor which command first will output to.
====================*/

/*======== void redirect_exec() ==========
Inputs: int base_fd
          char *first

Returns: None

Executes command first, then redirects its stdout to base_fd.
Reverts back to original file table when finished.
====================*/
```
