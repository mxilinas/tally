#include "countwords.h"
#include <stdio.h>
#include <stdlib.h>

/* Get the next word in a stream and write it to the buffer. */
int getWord(FILE *input, char *buffer) {

  int length = 0;
  int c;

  while ((c = getc(input)) != EOF) {

    if (length + 1 > MAX_WORD_LEN) {
      fprintf(stderr, "Maximum word length exceeded!");
      exit(EXIT_FAILURE);
    }

    switch (c) {
    case ' ':
    case '\n':
    case '\t':
      buffer[length] = '\0';
      return 1;
    }

    buffer[length++] = c;
  }

  buffer[length] = '\0';
  return EOF;
}
