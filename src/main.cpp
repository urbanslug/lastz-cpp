#include <iostream>
#include <string>
#include <sstream>

extern "C" {
  #include "lastz/src/lastz.h"
}


// First argument is the target, second is the query
int main(int argc, char *argv[]) {
  char* target = argv[1];
  char* query = argv[2];
  char* program_name = "";
  char* format = "--format=paf:wfmash";

  char* lastz_call[] = {
    program_name, // 0 can be an empty string no real need for this
    target,       // 1 the filename of the reference file
    query,        // 2 the filename of the query file
    format,       // 3 output format
  };

  std::cerr << "[lastz::align::computeAlignments] Performing lastz alignment " << std::endl;
  char* s2 = lastz(4, lastz_call);
  std::cerr << "[lastz::align::computeAlignments] Finished performing lastz alignment" << std::endl;

  std::string s(s2);
  free(s2);

  std::cout << s << std::endl;;
}
