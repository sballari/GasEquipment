#include "ModelloHeaders/funzioni.h"
#include <sstream>
#include <string>
#include <algorithm>

std::string ToString (int number ){
  std::ostringstream oss;
  oss<< number;
  return oss.str();
}
std::string ToString (unsigned int number ){
  std::ostringstream oss;
  oss<< number;
  return oss.str();
}
std::string ToString (double number ){
  std::ostringstream oss;
  oss<< number;
  return oss.str();
}

std::string ToString(bool val){
    return (val)? "vero":"falso";
}

std::string Minuscolo(std::string s){


    transform( s.begin(),s.end(), s.begin(),(int(*)(int)) tolower );
    return s;
}
