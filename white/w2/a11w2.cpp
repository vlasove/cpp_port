#include <iostream>
#include <map>
#include <string>

using namespace std;

void ChangeCapital(map<string, string>& m, string country, string new_capital){
    if (m.count(country) == 0){
        m[country] = new_capital;
        cout << "Introduce new country "<< country <<" with capital "<< new_capital<<endl;
    } else if (m[country] == new_capital) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
        cout << "Country "<<country<<" has changed its capital from "<< m[country] <<" to "<<new_capital<<endl;
        m[country] = new_capital;
    }
}

void Rename(map<string, string>& m, string old_name, string new_name){
    if (old_name == new_name || m.count(old_name) == 0 || m.count(new_name) != 0){
        cout << "Incorrect rename, skip" << endl;
    } else {
        cout <<"Country "<< old_name <<" with capital "<< m[old_name]<<" has been renamed to "<< new_name<<endl;
        m[new_name] = m[old_name];
        m.erase(old_name);
    }
}

void About(map<string, string> m, string country){
    if (m.count(country) == 0){
        cout << "Country "<< country<<" doesn't exist" << endl;
    } else {
        cout << "Country "<< country <<" has capital "<< m[country] << endl;
    }
}

void Dump(const map<string, string>& m){
    if(m.size() == 0){
        cout << "There are no countries in the world" << endl;
    } else {
        for(const auto& p : m){
            cout<<p.first << "/"<<p.second<<" ";
        }
        cout <<endl;
    }
}

int main(){
    map<string, string> booker;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string command;
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            ChangeCapital(booker, country, new_capital);
        } else if (command == "RENAME") {
            string old_name,new_name;
            cin >> old_name >> new_name;
            Rename(booker, old_name, new_name);
        } else if (command == "ABOUT") {
            string country;
            cin >> country;
            About(booker, country);
        } else {
            Dump(booker);
        }
    }
    return 0;
}