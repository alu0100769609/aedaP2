#include <iostream>
using namespace std;

const int MAX_SIZE = 20;
//typedef Complejo Complej;
//template <class TDATO>
class Complejo {
public:
   double realPart;
   double imaginaryPart;

public:
   Complejo();
   Complejo(double, double);
   ~Complejo();

public:
   void setRealPart(double);
   double getRealPart();
   void setImaginaryPart(double);
   double getImaginaryPart();
   Complejo& operator +(Complejo&);
   Complejo& operator -(Complejo&);
//   Complejo& operator -();
//   ostream& operator <<(ostream&,Complejo&);
//   istream& operator >>(istream&,istream&);
};

Complejo::Complejo() {
   //By default
}

Complejo::Complejo(double realPart, double imaginaryPart) {
   setRealPart(realPart);
   setImaginaryPart(imaginaryPart);
}

Complejo::~Complejo() {
   //By default
}

void Complejo::setRealPart(double realPart) {
   this->realPart = realPart;
}

double Complejo::getRealPart() {
   return realPart;
}

void Complejo::setImaginaryPart(double imaginaryPart) {
   this->imaginaryPart = imaginaryPart;

}

double Complejo::getImaginaryPart() {
   return imaginaryPart;
}

Complejo& Complejo::operator +(Complejo& c2) {
   return* (new Complejo(getRealPart() + c2.getRealPart(), getImaginaryPart() + c2.getImaginaryPart()));
}

Complejo& Complejo::operator -(Complejo& c2){
   return* (new Complejo(getRealPart() - c2.getRealPart(), getImaginaryPart() - c2.getImaginaryPart()));
}

ostream& operator << (ostream& os, Complejo& complejo) {
   os << "(" << complejo.getRealPart() << "+" << complejo.getImaginaryPart() << "i)";
   return os;
}

istream& operator >>(istream& is, Complejo& complejo) {
   char cadena[MAX_SIZE];
//   cout << "introduce parte real: ";
//   is >> complejo.realPart;
//   cout << "Introduce parte imaginaria: ";
//   is >> complejo.imaginaryPart;

   for (int i =0; i < MAX_SIZE; i++) {

   }

   cout << "Introduce complejo: ";
   is >> cadena;                                //is use char so save in char
   complejo.realPart = cadena[1] - '0';         //'0' = 49 in ascii
   complejo.imaginaryPart = cadena[3] - '0'; //'0' = 49 in ascii

   cout << "Parte real: " << complejo.realPart << endl;
   cout << "Parte imaginaria: " << complejo.imaginaryPart << endl;
   return is;
}
