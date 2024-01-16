#include "countwords.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Get the next word in a stream and write it to the buffer. */
int getWord(FILE *stream, char *buffer) {

  int length = 0;
  int c;

  while ((c = getc(stream)) != EOF) {

    if (length + 1 > MAX_WORD_LEN) {
      fprintf(stderr, "Maximum word length exceeded!\n%s\n", buffer);
      exit(EXIT_FAILURE);
    }

    if (ispunct(c) || c == ' ' || c == '\n') {
      buffer[length] = '\0';
      return 1;
    }

	if (isalpha(c))
		buffer[length++] = c;
  }

  buffer[length] = '\0';
  return EOF;
}
