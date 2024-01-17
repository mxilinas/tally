#include "countwords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
Entry *scan(Entry *e, char *word);
void printEntries(FILE *file, Entry *entries);
Entry *concat(Entry *e0, Entry *e1);
Entry *createEntry(Entry *next, int count, char *word);

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
void printHashmap(FILE *file, Entry *hashmap[]) {
  int i;
  for (i = 0; i < HASHMAP_SIZE; ++i) {
    printEntries(file, &(*hashmap[i]));
  }
}

/* Add a new entry to the dictionary. */
void addEntry(char *word, Entry *hashmap[]) {
  if (strcmp(word, "\0") == 0)
    return;
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
