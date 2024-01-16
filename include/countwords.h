#ifndef COUNTWORDS_H
#define COUNTWORDS_H

#define MAX_WORD_LEN 100
#define HASHMAP_SIZE 100000

typedef struct Entry {
  struct Entry *next;
  int count;
  char *word;
} Entry;

#endif
