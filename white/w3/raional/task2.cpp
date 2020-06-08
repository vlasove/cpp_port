#include <iostream>
#include <cmath>

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



