#include "../hpp/RPN.hpp"

RPN::RPN() {
   //Default constructor
}

RPN::~RPN() {
   //Default destructor
}

void RPN::printItems(Stack* stack) {
   cout << "Resultado: ";
   stack->printItems();
}

void RPN::pushItem(Stack* stack, int n) {
   stack->setHead(n);
}

int RPN::popItem(Stack* stack) {
   return stack->getFirst()->getElement();
}

void RPN::popItems(Stack* stack) {
   setValue1(popItem(stack));
   stack->deleteHead();                           //remove element from stack
   setValue2(popItem(stack));
   stack->deleteHead();                           //remove element from stack
}

void RPN::setValue1(int value1) {
   this->value1 = value1;
}

void RPN::setValue2(int value2) {
   this->value2 = value2;
}

int RPN::getValue1() {
   return value1;
}

int RPN::getValue2() {
   return value2;
}

void RPN::addition(Stack* stack) {
   stack->setHead(getValue2() + getValue1());
}

void RPN::substract(Stack* stack) {
   stack->setHead(getValue2() - getValue1());
}

void RPN::multiply(Stack* stack) {
   stack->setHead(getValue2() * getValue1());
}

void RPN::divide(Stack* stack) {
   stack->setHead(getValue2() / getValue1());
}

void RPN::run() {
   Stack* stack = new Stack();   //Creating our stack
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
      int n;
      cin >> n;
      pushItem(stack, n);
   }
   else {
      char op;
      cin >> op;
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
}while (!finCadena);
}
