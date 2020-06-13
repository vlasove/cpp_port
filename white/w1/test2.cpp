#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s = "hello";
    for (char c : s){
        cout << c <<endl;
    }

    vector<int> nums = {1,2,3,4,4,4,4,45,5,55,55,5,5};
    for (int n : nums){
        cout << n <<endl;
    }
    int quant = count(begin(nums), end(nums), 5);
    cout << quant <<endl;

    sort(begin(nums), end(nums));

    for (auto n : nums){
        cout << n<< ',';
    }
    cout <<endl;
}
