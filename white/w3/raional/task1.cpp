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

