#include "countwords.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* Get the next word in a stream and write it to the buffer. */
int getWord(FILE *stream, char *buffer) {

  int word_len = 0;
  int c;
  while ((c = getc(stream)) != EOF) {

    if (word_len + 1 > MAX_WORD_LEN) {
      fprintf(stderr, "Maximum word length exceeded!\n%s\n", buffer);
      exit(EXIT_FAILURE);
    }

    if (ispunct(c) || c == ' ' || c == '\n') {
      buffer[word_len] = '\0';
      return 1;
    }

	if (isalpha(c))
		buffer[word_len++] = tolower(c);
  }

  buffer[word_len] = '\0';
  return EOF;
}
