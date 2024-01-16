#include "countwords.h"
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

Entry *createEntry(Entry *, int, char *);
Entry *concat(Entry *, Entry *);
Entry *scan(Entry *, char *);
void printEntries(Entry *);
void freeEntries(Entry *);
Entry *lookup(char *, Entry **);
unsigned int hash(char *);
void printHashmap(Entry *[]);
int getWord(FILE *, char *);

/* Print the number of occurances of each word in stdin. */
int main(void) {

  Entry *entry;
  Entry *hashmap[HASHMAP_SIZE] = {NULL};
  char word[MAX_WORD_LEN];

  while (getWord(stdin, word) != EOF) {

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

  printHashmap(hashmap);

  return 0;
}
