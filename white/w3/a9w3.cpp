#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream input("input.txt");
    if (input){
        string line;
        while (getline(input, line)){
            cout << line <<endl;
        }
    } else {
        cout << "Error happend!"<<endl;
    }
    return 0;
}