#include "countwords.h"
#include <stdio.h>
#include <string.h>

/* Function Prototypes */
void addEntry(char *word, Entry *hashmap[]);
int getWord(FILE *stream, char *buffer);

/* Generate a dictionary of tallies from a given file */
void countWords(FILE *in, Entry *hashmap[]) {
  char word[MAX_WORD_LEN];

  while (getWord(in, word) != EOF)
    addEntry(word, hashmap);

  addEntry(word, hashmap);
}
