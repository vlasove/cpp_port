#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

void Add(map<string, set<string>>& synonyms, string word1, string word2){
    synonyms[word1].insert(word2);
    synonyms[word2].insert(word1);
}

void Check(map<string, set<string>>& synonyms, string word1, string word2){
    if (synonyms.count(word1) != 0 && synonyms.count(word2) != 0){
        if (synonyms[word1].count(word2) != 0 || synonyms[word2].count(word1) != 0){
            cout << "YES" <<endl;
        } else {
            cout << "NO" <<endl;
        }
    } else {
        cout << "NO" <<endl;
    }
}

void Count(map<string, set<string>>& synonyms, string word1){
    if (synonyms.count(word1) != 0){
        cout << synonyms[word1].size() <<endl;
    } else {
        cout << 0 << endl;
    }
}

int main(){
    int n;
    cin >> n;
    map<string, set<string>> synonyms;
    for(int i=0; i < n; i++){
        string command;
        cin >> command;
        if (command == "ADD"){
            string word1, word2;
            cin >>word1 >> word2 ;
            Add(synonyms, word1, word2);
        } else if (command == "CHECK"){
            string word1, word2;
            cin >>word1 >> word2 ;
            Check(synonyms, word1, word2);
        } else {
            string word1;
            cin >> word1;
            Count(synonyms, word1);
        }
    }
    return 0;
}