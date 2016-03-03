#include "Stack.hpp"
#include <string>    //string
#include <cctype>    //isdigit()

#include <iostream>
using namespace std;

class RPN {
private:
   //Stack  //almacena valor1 y valor2
   Stack stack;
   char op;
public:
   RPN();
   ~RPN();
   void run();
};
