#include <stdlib.h>
#include <stdio.h>

char** use_char(char** mystr) {

  char *ptr; // = NULL;
  size_t len; // = 0;
  FILE *f = open_memstream(&ptr, &len);

  fprintf(f, "hello, world: %d", 1234);
  fclose(f);
  printf("%d %.*s\n", (int) len, (int) len, ptr);

  size_t counter = 0;
  for(; *ptr != '\0'; ptr++, counter++) {
    mystr[counter] = ptr;
  }
  mystr[counter] = '\0';

  return mystr;
}


char* do_stream() {
  char   *ptr; // = NULL;
  size_t len;  // = 0;
  FILE   *f = open_memstream(&ptr, &len);

  fprintf(f, "First line\n");
  fprintf(f, "Second line");
  fclose(f);

  printf("%d\n", (int) len); // size of f

  char* out = malloc(((int) len * sizeof(char))+sizeof(char));

  size_t counter = 0;
  for(; *ptr; ptr++, counter++) {
    out[counter] = *ptr;
  }
  out[counter] = '\0';

  return out;
}
