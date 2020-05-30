#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintVector(const vector<int>& v){
    for (auto t : v){
        cout << t <<" ";
    }
    cout <<endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> queue;
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        
        if (command == "WORRY") {
            int person_id;
            cin >> person_id;
            queue[person_id] = 1;
        } else if (command == "QUIET"){
            int person_id;
            cin >> person_id;
            queue[person_id] = 0;
        } else if (command == "COME") {
            int amount;
            cin >> amount;
            if ( amount >= 0 ){
                queue.resize(queue.size() + amount, 0);
            } else {
                queue.resize(queue.size() + amount);
            } 
        } else {
            int worry_count = 0;
            for (auto p: queue){
                if (p == 1){
                    worry_count += p;
                }
            }
            cout << worry_count <<endl;
        }
    }

    return 0;
}