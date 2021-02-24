#include <iostream>
#include <string>

extern "C" {
  #include "lastz/src/lastz.h"
}

/*
  First argument is the target, second is the query
 */

int main(int argc, char *argv[]) {
  /*
    for(int i = 1; i < argc; i++) {
    std::cout << argv[i] << std::endl;
    }
   */

  size_t paf_len = 20000;
  char **s2 = (char**)malloc(paf_len*sizeof(char));

  char* target = argv[1];
  char* query = argv[2];
  char* program_name = "";
  char* format = "--format=paf:wfmash";

  char* lastz_call[] = {
    program_name,               // 0 can be an empty string no real need for this
    target,                // 1 the filename of the reference file
    query,                 // 2 the filename of the query file
    format, // 3 output format
  };

  std::cerr << "[lastz::align::computeAlignments] "
            << "Performing lastz alignment "
            << std::endl;

  lastz(s2, 4, lastz_call);

  std::cerr << "[lastz::align::computeAlignments] "
            << "Finished performing lastz alignment"
            << std::endl;

  std::string s;
  for(int counter = 0; *s2 ; s2++, counter++) {
    std::cout << counter << " ";
    s.push_back(**s2);
  }

  free(s2);

  std::cout << s << "\n";
}
