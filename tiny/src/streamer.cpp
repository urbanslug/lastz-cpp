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


  char* s2 = do_stream();

  std::string s;
  for(; *s2 ; *s2++) {
    s.push_back(*s2);
  }

  free(s2);


  std::cout << s << std::endl;
}
