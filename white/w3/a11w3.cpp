#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void PrintVec(const vector<int>& v){
    for(int i =0; i < v.size(); i++){
        cout << setfill(' ');
        cout << setw(10) << v[i];
        if (i != v.size() - 1){
            cout <<" ";
        }
    }
}

int main(){
    int n, m;
    ifstream input("input.txt");
    vector<int> bag;
    if (input){
        input >> n;
        input.ignore(1);
        input >> m;
        input.ignore(1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int trs;
                input >> trs;
                bag.push_back(trs);
                input.ignore(1);
            }
            PrintVec(bag);
            bag.clear();
            if (i != n -1){
                cout <<endl;
            }
        }


    } else {
        cout <<"Error happend!"<<endl;
    }
    return 0;
}