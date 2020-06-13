#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


int main(){
    ifstream input("input.txt");
    double num;
    while (input >> num){
        cout <<fixed << setprecision(3);
        cout << num <<endl;
    }
    return 0;
}