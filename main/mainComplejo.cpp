#include "../hpp/Complejo.hpp"
#include <iostream>

using namespace std;

int main() {

//   Complejo A(3,6);
   Complejo A;
   Complejo B;
   cin >> A;
   cin.ignore();
   cin >> B;
   Complejo C = A + B;
   cout << "El complejo final vale: " << C << endl;
}
