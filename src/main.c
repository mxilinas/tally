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

/* Print the number of occurances for each word in stdin. */
int main(void) {

  Entry *entries = NULL;
  char word[MAX_WORD_LEN];

  unsigned long count = 0;
  while (getWord(stdin, word) != EOF) {
	  ++count;

    if (entries == NULL) {
      entries = createEntry(NULL, 1, word);
      continue;
    }

    Entry *e;
    if ((e = scan(entries, word)) != NULL)
      ++(e->count);
    else {
      Entry *new = createEntry(NULL, 1, word);
      concat(entries, new);
    }
  }

  printEntries(entries);
  printf("%ld", count);
  freeEntries(entries);

  return 0;
}
