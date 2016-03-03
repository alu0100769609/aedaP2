#include "../hpp/RPN.hpp"

RPN::RPN() {
   //Default constructor
}

RPN::~RPN() {
   //Default destructor
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
      cout << "Resultado: ";
      stack->printItems();
   }
   else if (isdigit(c)){
      int n;
      cin >> n;
      stack->setHead(n);
//      cout << "Se introdujo en la pila: " << stack->getFirst()->getElement() << endl;
//      cout << "En la pila están: ";
//      stack->printItems();
   }
   else {
      char op;
      cin >> op;
      int value1 = stack->getFirst()->getElement();   //get element from stack
      stack->deleteHead();                           //remove element from stack
      int value2 = stack->getFirst()->getElement();   //get element from stack
      stack->deleteHead();                           //remove element from stack
      switch (op) {
         case '+':
            stack->setHead(value2 + value1);
            break;
         case '-':
            stack->setHead(value2 - value1);
            break;
         case '*':
            stack->setHead(value2 * value1);
            break;
         case '/':
            stack->setHead(value2 / value1);
            break;
      }
      //   if (c == "+-*/") {//+ = 43; - = 45; * = 42; / = 47;
//      cout << "You entered the word: " << str << endl;
//      cout << "No es un número y vale: " << str << endl;
   }
}while (!finCadena);
}
