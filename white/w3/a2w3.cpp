#include <iostream>
#include <locale>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool Compare(string a, string b){
    string thr = min(a,b);
    for(int i =0; i < thr.size();i++){
        if (tolower(a[i]) < tolower(b[i])){
            return true;
        }
    }
    return false;
}

void PrintVec(const vector<string>& v){
    for(const auto& elem : v){
        cout << elem<<" ";
    }
    cout <<endl;
}

int main(){
    int n;
    cin >> n;
    vector<string> vec(n);
    for(auto& el : vec){
        cin >> el;
    }
    sort(begin(vec), end(vec), [](string a, string b){
        return Compare(a,b);
    });

    PrintVec(vec);
    return 0;
}