#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
      words.push_back(s);
      SortStrings();
  };
  vector<string> GetSortedStrings() {
    return words;
  };
private:
    void SortStrings(){
        sort(begin(words), end(words));
    };

    vector<string> words;
};

