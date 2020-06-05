#include "file_handle.hpp"

vec_str read_Lines(const std::string path_to_file){
  vec_str lines;
  std::string line;
  std::ifstream file(path_to_file);

  if(file.is_open()){
    while(std::getline(file,line)){
      lines.push_back(line);
    }
  }
  else{
    throw FileNotFound("File : " + path_to_file + " not found");
    file.close();
  }
  file.close();
  return lines;
}
