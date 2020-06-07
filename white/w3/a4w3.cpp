#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
      FirstNames[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      LastNames[year] = last_name;
  }
  string GetFullName(int year) {
      vector<int> ChangedLastName;
      vector<int> ChangedFirstName;

      for(const auto& n : FirstNames){
          if (n.first <= year){
              ChangedFirstName.push_back(n.first);
          }
      }

      for(const auto& l : LastNames){
          if (l.first <= year){
              ChangedLastName.push_back(l.first);
          }
      }

      if (ChangedFirstName.size() == 0 && ChangedLastName.size() == 0){
          return "Incognito";
      } else if (ChangedFirstName.size() != 0 && ChangedLastName.size() == 0){
          return FirstNames[ChangedFirstName[ChangedFirstName.size() - 1]] + " with unknown last name";
      } else if (ChangedFirstName.size() == 0 && ChangedLastName.size() != 0){
          return LastNames[ChangedLastName[ChangedLastName.size() -1]] + " with unknown first name";
      } else {
          return FirstNames[ChangedFirstName[ChangedFirstName.size() - 1]] + " " + LastNames[ChangedLastName[ChangedLastName.size() -1]];
      }
    
  }
    string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
    }
private:
    map<int, string> FirstNames;
    map<int, string> LastNames;
};




int main(){
    Person person;
  
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}