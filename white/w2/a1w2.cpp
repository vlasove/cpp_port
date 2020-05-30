#include <iostream>

using namespace std;

int Factorial(int n){
    if (n <= 1){
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}

/*
int main(){
    for (int i =0; i <= 10; i++){
        cout<<Factorial(i)<<endl;
    }
    return 0;
}
*/