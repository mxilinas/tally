#include "countwords.h"
#include <stdlib.h>

typedef void *Hashmap;

Entry *scan(Entry *, char *);
void printEntries(Entry *entries);

/* Modulo hash function */
unsigned int hash(char *key) {
  unsigned int hash = 0;
  while (*key != '\0') {
    hash = (hash * 31) + *key;
    ++key;
  }
  return hash % HASHMAP_SIZE;
}

/* Return a pointer to the entry with the given word or NULL */
Entry *lookup(char *word, Entry *hashmap[]) {
  Entry *e;
  if ((e = hashmap[hash(word)]) == NULL)
    return NULL;
  else
    return scan(e, word);
}

/* Print all the words and counts in the hashmap */
void printHashmap(Entry *hashmap[]) {
  int i;
  for (i = 0; i < HASHMAP_SIZE; ++i) {
	  printEntries(&(*hashmap[i]));
  }
}
