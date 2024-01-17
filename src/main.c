#include "countwords.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Function Prototypes */
Entry *scan(Entry *, char *);
void printEntries(Entry *);
void freeEntries(Entry *);
void printHashmap(FILE *, Entry *[]);
void countWords(FILE *in, Entry *hashmap[]);

static const char *usage = "Usage: %s <input_file> [-o output_file]\n";

int main(int argc, char *argv[]) {

  FILE *input = stdin;
  FILE *output;
  int opt;

  while ((opt = (getopt(argc, argv, "o:"))) != -1) {
    switch (opt) {
    case 'i':
      input = fopen(optarg, "r");
      if (input == NULL) {
        fprintf(stderr, "%s: Could not read file %s\n", argv[0], argv[1]);
        fprintf(stderr, usage, argv[0]);
        exit(EXIT_FAILURE);
      }
      break;
    case 'o':
      output = fopen(optarg, "w");
      if (output == NULL) {
        fprintf(stderr, "%s: Could not create file %s\n", argv[0], optarg);
        exit(EXIT_FAILURE);
      }
      break;
    case '?':
      fprintf(stderr, usage, argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  if (input == stdin) {
    printf("\n");
    printf("-------- Word Tally --------.\n");
    printf("No input file specified.\n");
    printf("Reading from stdin.\n");
    printf("Press ctrl-d to submit text.\n");
    printf("Press ctrl-c to quit.\n");
    printf("----------------------------.\n");
    printf("\n");
  }

  Entry *hashmap[HASHMAP_SIZE] = {NULL};
  countWords(input, hashmap);
  printf("\n");
  fclose(input);

  if (output == NULL)
    printHashmap(stdout, hashmap);
  else {
    printHashmap(output, hashmap);
    fclose(output);
  }

  return 0;
}
