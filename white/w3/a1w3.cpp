#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std; 

void PrintVec(const vector<int>& v){
    for(const auto& elem : v){
        cout << elem<<" ";
    }
    cout <<endl;
}


int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto& i : vec){
        cin >> i;
    }
    sort(begin(vec), end(vec), [](int x, int y){
        return abs(x) < abs(y);
    });
    PrintVec(vec);

    return 0;

}