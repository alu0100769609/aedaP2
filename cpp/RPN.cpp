#include "../hpp/RPN.hpp"

RPN::RPN() {
   //Default constructor
}

RPN::~RPN() {
   //Default destructor
}

void RPN::run() {

   cout << "Please, enter a number or a word: ";
   bool finCadena = false;
   cin.ignore();
do{
   cout.flush();    // ensure output is written
   int a = cin.peek();  // peek character
   if (a != '\n')
      cin >> ws;  // eat up any leading white spaces
   int c = cin.peek();  // peek character

   if (c == '\n') {
      cout << "FIN DE CADENA" << endl;
      finCadena = true;
   }
   else if (isdigit(c)){
//   if (c == "+-*/") {//+ = 43; - = 45; * = 42; / = 47;
      int n;
      cin >> n;
//      cout << "You entered the number: " << n << endl;
      cout << "Es un número y vale: " << n << endl;
   }
   else {
      char str;
      //   if (c == "+-*/") {//+ = 43; - = 45; * = 42; / = 47;
      cin >> str;
//      cout << "You entered the word: " << str << endl;
      cout << "No es un número y vale: " << str << endl;
   }
}while (!finCadena);
}
