#include <iostream>
#include <string>

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
/*
int main(){
    cout<<IsPalindrom("madam");
    cout<<IsPalindrom("gentlman");
    cout<<IsPalindrom("X");
    return 0;
}
*/