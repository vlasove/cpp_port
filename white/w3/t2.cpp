#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream input("hello.txt");
    string line;
    if (input.is_open()){

        while (getline(input, line)){
            cout <<line <<endl;
        }
    } else {
        cout <<"File not exists!" <<endl;
    }

    ifstream input2("data.txt");
    if (input2.is_open()){
        string year, month, day;
        getline(input2, year, '-');
        getline(input2, month, '-');
        getline(input2, day, '-');

        cout <<year << " # " << month << " # "<<day<<endl;

    } else {
        cout <<"File not exists!"<<endl;
    }
    

    return 0;
}