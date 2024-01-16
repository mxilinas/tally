#include "countwords.h"
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

int getWord(FILE *, char *);
Entry *createEntry(Entry *next, int count, char *word);
Entry *scan(Entry *, char *);
Entry *concat(Entry *e0, Entry *e1);
void printEntries(Entry *entries);
void freeEntries(Entry *e);
Entry *lookup(char *word, Entry **hashmap);
unsigned int hash(char *key);
void printHashmap(Entry *hashmap[]);

/* Print the number of occurances for each word in stdin. */
int main(void) {

  /* Array of pointers to Entry */
  Entry *hashmap[HASHMAP_SIZE] = {NULL};

  char word[MAX_WORD_LEN];

  unsigned long count = 0;
  while (getWord(stdin, word) != EOF) {
    ++count;

    Entry *e;
    if ((e = lookup(word, hashmap)) != NULL)
      ++(e->count);
    else {
      unsigned int hashCode = hash(word);
	  if (hashmap[hashCode] == NULL)
		  hashmap[hashCode] = createEntry(NULL, 1, word);
	  else
		 concat(hashmap[hashCode], createEntry(NULL, 1, word));
    }
  }

  printHashmap(hashmap);
  printf("%ld", count);

  return 0;
}
