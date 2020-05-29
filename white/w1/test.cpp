#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    cout << "Hello world!"<<endl;
    vector<int> kek = {1,2,3};

    cout <<kek.size()<<endl;
    map<string , int> lol;
    lol["one"] = 1;
    lol["two"] = 2;

    cout<< lol["two"]<<endl;

    return 0;
}