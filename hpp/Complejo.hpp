#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

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
   Complejo operator +(const Complejo) const;
   Complejo operator -(const Complejo) const;
   Complejo operator *(const Complejo) const;
   Complejo operator /(const Complejo) const;
   Complejo operator -() const;
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

Complejo Complejo::operator +(const Complejo c2) const {
   return (Complejo(getRealPart() + c2.getRealPart(), getImaginaryPart() + c2.getImaginaryPart()));
}

Complejo Complejo::operator -(const Complejo c2) const {
   return (Complejo(getRealPart() - c2.getRealPart(), getImaginaryPart() - c2.getImaginaryPart()));
}

Complejo Complejo::operator -() const {
   return (Complejo(-getRealPart(), -getImaginaryPart()));
}

Complejo Complejo::operator *(const Complejo c2) const {
   return (Complejo(getRealPart() * c2.getRealPart(), getImaginaryPart() * c2.getImaginaryPart()));
}

Complejo Complejo::operator /(const Complejo c2) const {
   return (Complejo(getRealPart() / c2.getRealPart(), getImaginaryPart() / c2.getImaginaryPart()));
}

ostream& operator << (ostream& os, const Complejo& complejo) {
   os << "(" << complejo.getRealPart() << "+" << complejo.getImaginaryPart() << "i)";
   return os;
}

istream& operator >>(istream& is, Complejo& complejo) {
   is >> ws;                     // eat up any leading white spaces (except eof by if)

   int c = is.peek();            // peek character
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
               is >> num;
               complejo.setImaginaryPart(num);
               c = is.peek();
               if (c == ')') {
                  is >> aux;
                  return is;
               }
            }
         }
      }
   }
   cout <<"Oops... Something is wrong here" << endl;
}
