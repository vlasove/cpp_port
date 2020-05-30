#include <iostream>
#include <vector>

using namespace std;

int Average(const vector<int>& temp){
    int avg;
    int s = 0;
    for (auto t : temp){
        s += t;
    }
    avg = s / temp.size();
    return avg;
}

void PrintVector(const vector<int>& nums){
    for(auto n : nums){
        cout << n << " ";

    }
    cout<<endl;
}

void CheckTemp(const vector<int>& temp, int avg){
    vector<int> answer;
    for (int i = 0; i < temp.size(); i++){
        if (temp[i] > avg){
            answer.push_back(i);
        }
    }
    cout << answer.size() <<endl;
    PrintVector(answer);
}

int main(){
    int n;
    cin >> n;
    vector<int> temp(n);
    for(int& t : temp){
        cin >> t;
    }
    CheckTemp(temp, Average(temp));
    return 0;
}