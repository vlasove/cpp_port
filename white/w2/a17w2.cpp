#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;


int main(){

    int n;
    cin >> n;
    map<set<string>, int> book;
    for(int i =0; i < n; i++){
        int bus_num;
        cin >> bus_num;
        set<string> buses; 
        for(int j =0; j < bus_num; j++){
            string bus;
            cin >> bus;
            buses.insert(bus);
        }
        if(book.count(buses) == 0){
            cout << "New bus " << book.size() + 1<<endl;
            auto k = book.size() + 1;
            book[buses] = k;
        } else {
            cout << "Already exists for "<< book[buses]<<endl;
        }
    }
    return 0;
}