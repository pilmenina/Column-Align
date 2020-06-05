#include <iostream>
#include "file_handle.hpp"
#include <exception>
#include <iomanip> // std::setw
#include <algorithm>

#define PADDING 10

int get_max_width(vec_str lines);

int main(int argc, char* argv[]){
  if(argc < 4){
    std::cout << "Usage : <program> <file_1> <file_2> <file_3>" << std::endl;
    return 1;
  }

  try{
    // Read the lines from the given files
    vec_str v1 = read_Lines(argv[1]);
    vec_str v2 = read_Lines(argv[2]);
    vec_str v3 = read_Lines(argv[3]);

    int v1_width = get_max_width(v1);
    int v2_width = get_max_width(v2);
    int v3_width = get_max_width(v3);

    int max_iterator = std::max(std::max(v1.size(),v2.size()), std::max(v2.size(),v3.size()));

    for(int i = 0; i < max_iterator; i++){
      std::cout << std::left << std::setw(v1_width + PADDING) << ((v1.size() > i) ? v1[i] : "")
                << std::left << std::setw(v2_width + PADDING) << ((v2.size() > i) ? v2[i] : "")
                << std::left << std::setw(v3_width + PADDING) << ((v3.size() > i) ? v3[i] : "")
                << std::endl;
    }
  }
  catch (FileNotFound& ex){
    std::cout << ex.get_msg() << std::endl;
    return 1;
  }

  return 0;
}

int get_max_width(vec_str lines){
  int max = 0;
  for(auto line : lines){
    if(line.size() > max)
      max = line.size();
  }
  return max;
}
