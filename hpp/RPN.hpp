#include "Stack.hpp"
#include <string>             //string
#include <cctype>             //isdigit()

#include <iostream>
using namespace std;

template <class TDATO>
class RPN {
private:                      //Attributes
   Stack<TDATO> stack;
   TDATO value1;
   TDATO value2;

public:                       //Default constructor & destructor
   RPN(void){}
   ~RPN(void){}

public:                       //Access methods
   void setValue1(TDATO value1){ this->value1 = value1; }
   TDATO getValue1(void) { return value1; }
   void setValue2(TDATO value2) { this->value2 = value2; }
   TDATO getValue2(void) { return value2; }
   void pushItem(Stack<TDATO>* stack, TDATO item) { stack->setHead(item); }//Push into stack
   TDATO popItem(Stack<TDATO>* stack) { return stack->getFirst()->getElement(); }//Pop from stack

private:                      //Methods that can't be called from outside the class
   void addition(Stack<TDATO>* stack) { stack->setHead(getValue2() + getValue1()); }       //Add two numbers and push result into stack
   void substract(Stack<TDATO>* stack) { stack->setHead(getValue2() - getValue1()); }      //Substract two numbers and push result into stack
   void multiply(Stack<TDATO>* stack) { stack->setHead(getValue2() * getValue1()); }       //Multiply two numbers and push result into stack
   void divide(Stack<TDATO>* stack) { stack->setHead(getValue2() / getValue1()); }         //Divide two numbers and push result into stack

public:
   void printItems(Stack<TDATO>* stack) {     //Print stack items
      cout << "Resultado: ";
      stack->printItems();
   }
   void popItems(Stack<TDATO>* stack) {       //Pop 2 items and set them into value1 & value2
      setValue1(popItem(stack));
      stack->deleteHead();                           //remove element from stack
      setValue2(popItem(stack));
      stack->deleteHead();                           //remove element from stack
   }
   void run(void) {            //Run RPN calculator
      Stack<TDATO>* stack = new Stack<TDATO>();   //Creating our stack
      bool finCadena = false;

      cin.ignore();                 //skip the enter buffered from call
      cout << "Please, enter your expression: ";
      do{
         cout.flush();                 // ensure output is written
         int a = cin.peek();           // first peek just to catch \n
         if (a != '\n')
            cin >> ws;                 // eat up any leading white spaces (except eof by if)

         int c = cin.peek();           // peek character
         if (c == '\n') {
            finCadena = true;
            printItems(stack);
         }
         else if (isdigit(c)){
            TDATO item;
            cin >> item;
            pushItem(stack, item);
         }
         else {
            char op;
            cin >> op;
            if ((op == '-') && isdigit(cin.peek())) {   //If -3 || +4
               TDATO item;
               cin >> item;
               pushItem(stack, -item);
            }
            else if ((op == '+') && isdigit(cin.peek())) {
               TDATO item;
               cin >> item;
               pushItem(stack, item);
            }
            else {
               popItems(stack);
               switch (op) {
                  case '+':
                     addition(stack);
                     break;
                  case '-':
                     substract(stack);
                     break;
                  case '*':
                     multiply(stack);
                     break;
                  case '/':
                     divide(stack);
                     break;
               }
            }
         }
      }while (!finCadena);
   }
};
