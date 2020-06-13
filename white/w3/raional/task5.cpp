#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        int total = numerator * denominator;
        if (total > 0){
            num = abs(numerator);
            den = abs(denominator);
        } else {
            num = abs(numerator) * -1;
            den = abs(denominator);
        }

        if (num == 0){
            den = 1;
        }
        int nod = gcd(abs(num), den);
        num = num / nod;
        den = den / nod;
       
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }
    

private:
    int gcd(int a, int b){
        while(a > 0 && b > 0){
            if(a > b)
                a %= b;
            else
                b %= a;
        }
        return a + b;
    }
    int num;
    int den;
};

bool operator == (const Rational& lhs, const Rational& rhs){
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()){
        return true;
    }
    return false;
}

Rational operator +(const Rational& lhs, const Rational& rhs){
    int total_num = lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator();
    int total_den = lhs.Denominator() * rhs.Denominator();
    return Rational(total_num, total_den);
}

Rational operator -(const Rational& lhs, const Rational& rhs){
    int total_num = lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator();
    int total_den = lhs.Denominator() * rhs.Denominator();
    return Rational(total_num, total_den);
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}


Rational operator /(const Rational& lhs, const Rational& rhs){
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;
  
  if (is) {
      is >> n >> c >> d;
      if (is && c == '/') {
          r = Rational(n, d);
      }
  }
  
  return is;
}

ostream& operator <<(ostream& stream, const Rational& rational){
    stream<<rational.Numerator() <<"/"<<rational.Denominator();
    return stream;
}

bool operator <(const Rational& lhs, const Rational& rhs){
    return (lhs - rhs).Numerator() < 0;
}
