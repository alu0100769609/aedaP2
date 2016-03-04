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
//ToDo: Llamar a printItems();
      cout << "Resultado: ";
      stack->printItems();
//FinToDo
   }
   else if (isdigit(c)){
//ToDo: Llamar a pushItem();
      int n;
      cin >> n;
      stack->setHead(n);
//FinToDo

//      cout << "Se introdujo en la pila: " << stack->getFirst()->getElement() << endl;
//      cout << "En la pila están: ";
//      stack->printItems();
   }
   else {
      char op;
      cin >> op;
//ToDo: Llamar a popItems(); que debe llamar a popItem();
      int value1 = stack->getFirst()->getElement();   //get element from stack
      stack->deleteHead();                           //remove element from stack
      int value2 = stack->getFirst()->getElement();   //get element from stack
      stack->deleteHead();                           //remove element from stack
//FinToDo
      switch (op) {
         case '+':
//ToDo: Llamar a addition()
            stack->setHead(value2 + value1);
            break;
         case '-':
//ToDo: Llamar a substract()
            stack->setHead(value2 - value1);
            break;
         case '*':
//ToDo: Llamar a multiply()
            stack->setHead(value2 * value1);
            break;
         case '/':
//ToDo: Llamar a divide()
            stack->setHead(value2 / value1);
            break;
      }
   }
}while (!finCadena);
}
