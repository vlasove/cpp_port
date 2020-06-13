#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool IsPalindrom(string word){
    if (word.size() == 0){
        return true;
    } else {
        string sample;
        for (int i = word.size() -1 ; i >= 0; i--){
            sample += word[i];
        }
        if (word == sample){
            return true;
        }
        return false;
    }
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> answer;
    for (auto word: words){
        if (IsPalindrom(word) && word.size() >= minLength){
            answer.push_back(word);
        }
    }
    return answer;
}

void PrintVector(vector<string> words){
    for(auto c: words){
        cout << c << " ";
    }
    cout <<endl;
}

/*
int main(){
    vector<string> v1 = {"abacaba", "aba"};
    vector<string> v2 = {"abacaba", "aba"};
    vector<string> v3 = {"weew", "bro", "code"};

    PrintVector(PalindromFilter(v1, 5));
    PrintVector(PalindromFilter(v2, 2));
    PrintVector(PalindromFilter(v3, 4));
    return 0;
}
*/