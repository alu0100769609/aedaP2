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
   double getRealPart() const;
   void setImaginaryPart(double);
   double getImaginaryPart() const;
   Complejo& operator +(const Complejo&) const;
   Complejo& operator -(const Complejo&) const;
   Complejo& operator *(const Complejo&) const {};
   Complejo& operator /(const Complejo&) const {};
   Complejo& operator -() const;
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

double Complejo::getRealPart() const {
   return realPart;
}

void Complejo::setImaginaryPart(double imaginaryPart) {
   this->imaginaryPart = imaginaryPart;

}

double Complejo::getImaginaryPart() const {
   return imaginaryPart;
}

Complejo& Complejo::operator +(const Complejo& c2) const {
   return* (new Complejo(getRealPart() + c2.getRealPart(), getImaginaryPart() + c2.getImaginaryPart()));
}

Complejo& Complejo::operator -(const Complejo& c2) const {
   return* (new Complejo(getRealPart() - c2.getRealPart(), getImaginaryPart() - c2.getImaginaryPart()));
}

Complejo& Complejo::operator -() const {
   return* (new Complejo(-getRealPart(), -getImaginaryPart()));
}

ostream& operator << (ostream& os, const Complejo& complejo) {
   os << "(" << complejo.getRealPart() << "," << complejo.getImaginaryPart() << ")";
   return os;
}

istream& operator >>(istream& is, Complejo& complejo) {
   is >> ws;                 // eat up any leading white spaces (except eof by if)

   int c = is.peek();           // peek character
   if (c == '('){
      char aux;
      is >> aux;
      c = is.peek();
      if (isdigit(c)){
         double num;
         is >> num;
         complejo.setRealPart(num);
         c = is.peek();
         if (c == ','){
            is >> aux;
            c = is.peek();
            if (isdigit(c)) {
               // double num;
               is >> num;
               complejo.setImaginaryPart(num);
               c = is.peek();
               if (c == ')') {
                  return is;
               }
            }
         }
      }
   }
   cout <<"Algo salió mal" << endl;
/*   if (isdigit(c)){
      TDATO item;
      cin >> item;
      //         cout << "El item es: " << item << endl;
      //         cout << "Real de item: " << item.getRealPart() << endl;
      //         cout << "Imag de item: " << item.getImaginaryPart() << endl;
      pushItem(stack, item);
   }
   else {
      char op;
      cin >> op;
   }
   cout << "Introduce complejo: ";
   is >> cadena;                                //is use char so save in char
   complejo.realPart = cadena[1] - '0';         //'0' = 49 in ascii
   complejo.imaginaryPart = cadena[3] - '0'; //'0' = 49 in ascii

   cout << "Parte real: " << complejo.realPart << endl;
   cout << "Parte imaginaria: " << complejo.imaginaryPart << endl;
   return is;
*/
}
