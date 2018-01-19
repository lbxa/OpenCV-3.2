/*
**\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
**                       AUXILARY HEADER
**
**  ATTENTION: 
**  This header is made for the pure purpose of simplifying normal STL functions
**  with minimal depedencies. 
**
**  27.05.2017 | Lucas Barbosa (C) | Open Source Software Movement 
*/

#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace aux {

  std::string itostr (int integer) {
    std::string streamedString;
    std::ostringstream converter;
    converter << integer;
    return converter.str();
  }

  int strtoi (const std::string &str) {
    std::istringstream converter(str);
    int result;
    converter >> result;
    return result;
  }

  // ANSI coloring

  ostream& bold_on(ostream& output_stream) {
    return output_stream << "\e[1m";
  }

  ostream& blackBG_on(ostream& output_stream) {
    return output_stream << "\e[40;37m";
  }

  ostream& color_off(ostream& output_stream) {
    return output_stream << "\e[0m";
  }

} // end of aux namespace

#endif // AUX_H_INCLUDED
