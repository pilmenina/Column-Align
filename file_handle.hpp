#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>

typedef std::vector<std::string> vec_str;

vec_str read_Lines(const std::string path_to_file);

class FileNotFound : public std::exception{
private:
  std::string msg;
public:
  FileNotFound(const std::string msg){
    this->msg = msg;
  }
  std::string get_msg(){return this->msg;}
};
