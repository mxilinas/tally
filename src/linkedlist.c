#include "countwords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Add e1 to the end of e0 */
Entry *concat(Entry *e0, Entry *e1) {
  Entry *head;
  for (head = e0; head->next != NULL; head = head->next)
    ;
  head->next = e1;
  return e0;
}

/* Return a pointer to the entry with the given word */
Entry *scan(Entry *e, char *word) {

  Entry *head;
  for (head = e; head != NULL; head = head->next)

    if (strcmp(word, head->word) == 0)
      return head;
  return NULL;
}

/* Print a list of words and their number of occurances. */
void printEntries(Entry *entries) {
  Entry *head;
  for (head = entries; head != NULL; head = head->next)
    printf("%-20s%3d\n", head->word, head->count);
}

/* Create a new entry */
Entry *createEntry(Entry *next, int count, char *word) {
  Entry *new_entry = (Entry *)malloc(sizeof(Entry));

  /* Allocate memory for new word. */
  char *new_word = (char *)malloc(sizeof(char) * strlen(word) + 1);
  new_entry->word = strcpy(new_word, word);

  new_entry->next = next;
  new_entry->count = count;
  return new_entry;
}

/* Free entries and their words. */
void freeEntries(Entry *e) {
  Entry *head;
  Entry *temp_next;
  for (head = e; head != NULL; head = temp_next) {
    free(head->word);
    temp_next = head->next;
    free(head);
  }
}
