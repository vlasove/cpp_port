#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void PrintVector(const vector<string>& v){
    for(auto el : v){
        cout << el << " ";
    }
    cout <<endl;
}


int main(){
    string a = "abc";
    string b = "bca";

    vector<string> c = {"bca", "abc", "A"};
    PrintVector(c);
    sort(begin(c), end(c));
    PrintVector(c);

    vector<int> vec = {1,2,3,4,5,6,2,3,4,1,123,2};

    cout <<min(b,a)<<endl;
    cout << max(a,b)<<endl;

    cout << count(begin(c), end(c), "A")<<endl;
    int thr;
    cin >> thr;

    cout <<count_if(begin(vec), end(vec), [thr](int x) {
        if (x > thr){
            return true;
        }
        return false;
    });
    cout <<endl;
    return 0;
}