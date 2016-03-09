#include <iostream>
using namespace std;

class Rational {
   friend class RPN<Rational>;         //Allow class RPN to access method operator -
public:
   int numerator;
   int denominator;

public:
   Rational();
   Rational(int, int);
   ~Rational();

public:
   void setNumerator(int);
   int getNumerator() const;
   void setDenominator(int);
   int getDenominator() const;

private:
   void gcd ();
   Rational operator +(const Rational) const;
   Rational operator -(const Rational) const;
   Rational operator *(const Rational) const;
   Rational operator /(const Rational) const;
   Rational operator -() const;
};

Rational::Rational() {
   //By default
}

Rational::Rational(int numerator, int denominator) {
   setNumerator(numerator);
   setDenominator(denominator);
}

Rational::~Rational() {
   //By default
}

void Rational::setNumerator(int numerator) {
   this->numerator = numerator;
}

int Rational::getNumerator() const {
   return numerator;
}

void Rational::setDenominator(int denominator) {
   this->denominator = denominator;

}

int Rational::getDenominator() const {
   return denominator;
}

void Rational::gcd () {
   int  gcd;
   for(int i = 1; i <= getNumerator() && i <= getDenominator(); i++)
      if(getNumerator() % i == 0 && getDenominator() % i == 0 )
         gcd = i;
   setNumerator(getNumerator() / gcd);
   setDenominator(getDenominator() / gcd);
}

Rational Rational::operator +(const Rational r2) const {
   Rational result = (Rational((getNumerator() * r2.getDenominator()) + (r2.getNumerator() * getDenominator()),
                     getDenominator() * r2.getDenominator()));
   result.gcd();
   return result;
}

Rational Rational::operator -(const Rational r2) const {
   Rational result = (Rational((getNumerator() * r2.getDenominator()) - (r2.getNumerator() * getDenominator()),
                     getDenominator() * r2.getDenominator()));
   result.gcd();
   return result;
}

Rational Rational::operator -() const {
   return (Rational(-getNumerator(), getDenominator()));
}

Rational Rational::operator *(const Rational r2) const {
   Rational result = (Rational(getNumerator() * r2.getNumerator(), getDenominator() * r2.getDenominator()));
   result.gcd();
   return result;
}

Rational Rational::operator /(const Rational r2) const {
   Rational result = (Rational(getNumerator() * r2.getDenominator(), getDenominator() * r2.getNumerator()));
   result.gcd();
   return result;
}

ostream& operator << (ostream& os, const Rational& rational) {
   os << rational.getNumerator() << "/" << rational.getDenominator();
   return os;
}

istream& operator >>(istream& is, Rational& rational) {
   is >> ws;                     // eat up any leading white spaces (except eof by if)

   int c = is.peek();            // peek character
   if (c == '{'){
      char aux;
      is >> aux;
      c = is.peek();
      if (isdigit(c)){
         double num;
         is >> num;
         rational.setNumerator(num);
         c = is.peek();
         if (c == '/'){
            is >> aux;
            c = is.peek();
            if (isdigit(c)) {
               is >> num;
               rational.setDenominator(num);
               c = is.peek();
               if (c == '}') {
                  is >> aux;
                  return is;
               }
            }
         }
      }
   }
   cout <<"Oops... Something is wrong here" << endl;
}
