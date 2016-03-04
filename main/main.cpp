#include <cstdlib>      //system()
#include "../hpp/RPN.hpp"
#include <iostream>

using namespace std;

int main(void) {
   bool exitMain = false;
   int option;

   RPN<int>* calculator = new RPN<int>();
   do {
      cout << "Reverse Polish Notation Calculator (RPN Calculator)\n"
           << "---------------------------------------------------\n" << endl;

      cout << "    0.- Exit\n"
           << "    1.- Set & evaluate expression\n" << endl;
      cin >> option;
      system("clear");
      switch (option) {
         case 0:
            exitMain = true;
            break;
         case 1:
            calculator->run();
            break;
         default:
            cout << "Wrong choice, please try again...\n" << endl;
      }
   } while(!exitMain);
   return 0;
}
