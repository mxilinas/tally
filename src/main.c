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

/* Write out the number of occurances of each word in input file. */
int main(int argc, char *argv[]) {

  FILE *input, *output;
  int opt;

  if (argc < 2) {
    fprintf(stderr, "%s: No input file specified.\n", argv[0]);
    fprintf(stderr, "Usage: %s <input_file> [-o output_file]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  input = fopen(argv[1], "r");
  if (input == NULL) {
    fprintf(stderr, "%s: Could not read file %s\n", argv[0], argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((opt = (getopt(argc, argv, "o:"))) != -1) {
    switch (opt) {
    case 'o':
      output = fopen(optarg, "w");
      if (output == NULL) {
        fprintf(stderr, "%s: Could not create file %s\n", argv[0], optarg);
        exit(EXIT_FAILURE);
      }
      break;
    case '?':
      fprintf(stderr, "Usage: %s <input_file> [-o output_file]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  Entry *hashmap[HASHMAP_SIZE] = {NULL};
  countWords(input, hashmap);
  fclose(input);

  if (output == NULL)
	  printHashmap(stdout, hashmap);
  else {
	  printHashmap(output, hashmap);
	  fclose(output);
  }

  return 0;
}
