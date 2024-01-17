#include "countwords.h"
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
int getWord(FILE *, char *);
Entry *lookup(char *, Entry **);
Entry *concat(Entry *, Entry *);
Entry *createEntry(Entry *, int, char *);
unsigned int hash(char *);

/* Add a new entry to the dictionary. */
void addEntry(char *word, Entry *hashmap[]) {
  Entry *entry;
  unsigned int hashCode = hash(word);
  if ((entry = lookup(word, hashmap))) {
    ++(entry->count);
  } else {
    if ((entry = hashmap[hashCode]))
      concat(entry, createEntry(NULL, 1, word));
    else
      hashmap[hashCode] = createEntry(NULL, 1, word);
  }
}

/* Generate a dictionary of tallies from a given file */
void countWords(FILE *in, Entry *hashmap[]) {
  char word[MAX_WORD_LEN];

  while (getWord(in, word) != EOF)
    addEntry(word, hashmap);

  addEntry(word, hashmap);
}
