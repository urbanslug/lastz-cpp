#include <iostream>
#include <string>
#include <sstream>

extern "C" {
  #include "streams.h"
}

int main() {
  char **s1 = (char**)malloc(200*sizeof(char));
  use_char(s1);

  free(s1);

  std::stringstream s;
  //do_stream(&s);

  /*
  for(size_t i = 0; i < 20; i++)
    printf("%c", s2[i]);
  printf("\n");
  */


}
