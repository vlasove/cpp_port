#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    if (input && output){
        string line;
        while (getline(input, line)){
            output << line <<endl;
        }
    } else {
        cout << "Error happend!"<<endl;
    }
    return 0;
}