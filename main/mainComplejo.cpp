#include "../hpp/Complejo.hpp"
#include <iostream>

using namespace std;

int main() {

//   Complejo A(3,6);
   Complejo A;
   Complejo B;
   int c;
   cout << "Introduce un int: ";
   cin >> c;
   cin >> A;
   cin >> B;
   Complejo C = A + B;
   cout << "El complejo final vale: " << C << "y c vale " << c << endl;
}
