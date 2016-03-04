#include "Stack.hpp"
#include <string>             //string
#include <cctype>             //isdigit()

#include <iostream>
using namespace std;

class RPN {
private:                      //Attributes
   Stack stack;
   int value1;
   int value2;

public:                       //Default constructor & destructor
   RPN(void);
   ~RPN(void);

public:                       //Access methods
   void setValue1(int);
   int getValue1(void);
   void setValue2(int);
   int getValue2(void);
   void pushItem(Stack*, int);//Push into stack
   int popItem(Stack*);         //Pop from stack

private:                      //Methods that can't be called from outside the class
   void addition(Stack*);       //Add two numbers and push result into stack
   void substract(Stack*);      //Substract two numbers and push result into stack
   void multiply(Stack*);       //Multiply two numbers and push result into stack
   void divide(Stack*);         //Divide two numbers and push result into stack

public:
   void printItems(Stack*);     //Print stack items
   void popItems(Stack*);       //Pop 2 items and set them into value1 & value2
   void run(void);            //Run RPN calculator
};
