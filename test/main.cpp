#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>  // sort()
#include <unistd.h> // getopt()

void alphabet_code(){
  std::vector<char> alphapet{'a', 'z', 'A', 'Z'};
  for(std::vector<char>::iterator it = alphapet.begin(); it != alphapet.end(); ++it) {
    /* loop for vector */
    int intAlpha = *it;
    // std::cout << intAlpha << std::endl;
  }
}

std::string sort_ascii(const char* input_chars){
  const std::string input_string(input_chars);
  std::vector<char> oneVec(std::make_move_iterator(input_string.cbegin()), 
                        std::make_move_iterator(input_string.cend()));
  std::sort(oneVec.begin(), oneVec.end());
  std::string sorted_string(oneVec.begin(), oneVec.end());
  return sorted_string;

}

void mbs_to_wchar(const char * arg_string){
  const char * p = arg_string;
  std::wstring wstr(30, L'#');
  mbstowcs(&wstr[0], p, 30);
 
}

int main(int argc, char** argv)
{ 
  int c;
  bool rawdump = false;
  bool apidump = false;
  while ((c = getopt(argc, argv, "da")) != -1) {
    switch (c) {
    case 'd':
      rawdump = true;
      break;
    case 'a':
      apidump = true;
      break;
    default:
      abort();
    }
  }

  const char * cstr = argv[argc - 1];
  const std::string sorted_str = sort_ascii(cstr);
  if(apidump){
    std::cout << sorted_str << std::endl;
    std::cout << apidump << std::endl;
    std::cout << rawdump << std::endl;

  } else {
    if(rawdump){

    }
  }

  return 0;

}
