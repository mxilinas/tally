#ifndef COUNTWORDS_H
#define COUNTWORDS_H

#define MAX_WORD_LEN 50

typedef struct Entry {
  struct Entry *next;
  int count;
  char *word;
} Entry;

#endif
