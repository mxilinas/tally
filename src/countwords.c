#include "countwords.h"
#include <stdio.h>
#include <stdlib.h>


/* Function Prototypes */
int getWord(FILE *, char *);
Entry *lookup(char *, Entry **);
Entry *concat(Entry *, Entry *);
Entry *createEntry(Entry *, int, char *);
unsigned int hash(char *);


/* Generate a dictionary of tallies from a given file */
void countWords(FILE *in, Entry *hashmap[]) {
  Entry *entry;
  char word[MAX_WORD_LEN];

  while (getWord(in, word) != EOF) {

    if ((entry = lookup(word, hashmap))) {
      ++(entry->count);
      continue;
    }

    unsigned int hashCode = hash(word);
    if ((entry = hashmap[hashCode]))
      concat(entry, createEntry(NULL, 1, word));
    else
      hashmap[hashCode] = createEntry(NULL, 1, word);
  }
}
