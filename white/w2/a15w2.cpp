#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;
    for(auto p : m){
        result.insert(p.second);
    }
    return result;
}

/*
int main(){
    return 0;
}
*/