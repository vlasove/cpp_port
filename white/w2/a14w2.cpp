#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    set<string> words;
    int n;
    cin >> n;
    for(int i =0; i < n; i++){
        string word;
        cin >> word;
        words.insert(word);
    }
    cout << words.size()<< endl;
}