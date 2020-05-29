#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float a,b,c;
    cin >> a >> b >> c;
    if (a == 0 ){
        //linear bx + c = 0 |||| x = -c/b
        if (b == 0){
            cout <<endl;
        } else {
            cout << -c/b <<endl;
        }
    } else {
        auto d = b * b - 4 * a * c;
        auto sq_d = sqrt(d);

        if (d > 0 ){
            auto x1 = (-b + sq_d) / (2 * a);
            auto x2 = (-b - sq_d) / (2 * a);
            cout << x1 << " "<< x2<<endl;
        } else if (d == 0){
            cout << (-b)/(2*a) <<endl;
        } else {
            cout <<endl;
        }
    }
    return 0;
}