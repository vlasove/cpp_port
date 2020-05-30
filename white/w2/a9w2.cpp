#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintTasks(const vector<vector<string>>& tasks, int day){
    auto tasks_in_day = tasks[day-1].size();
    if (tasks_in_day == 0){
        cout << tasks_in_day<<endl;
    } else {
        cout << tasks_in_day << " ";
        for (auto t : tasks[day-1]){
            cout << t <<" ";
        }
        cout <<endl;
    }

}

int main(){
    int months_counter = 0;
    vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;
    vector<vector<string>> tasks(days_in_months[current_month]);
    
    int n;
    cin >> n ;
    for (int i =0; i < n; i++){
        string command;
        cin >> command;
        if (command == "ADD"){
            int day;
            string task;
            cin >> day >> task;
            tasks[day - 1].push_back(task);
        } else if (command == "DUMP") {
            int day;
            cin >> day;
            PrintTasks(tasks, day);
        } else {
            int previous_month = current_month;

            current_month++;
            current_month = current_month % 12;
            if (days_in_months[previous_month] < days_in_months[current_month]){
                //если в следующем месяце дней больше чем в текущем
                tasks.resize(tasks.size() + (days_in_months[current_month] - days_in_months[previous_month]));
            } else {
                //если в следующем месяце дней меньше чем в текущем
                vector<string> dump;
                for(int j = days_in_months[current_month] -1; j < days_in_months[previous_month]; j++) {
                    if (tasks[j].size() != 0) {
                        for(auto t : tasks[j]){
                            dump.push_back(t);
                        }
                    }

                }
                tasks.resize(days_in_months[current_month]);
                tasks[days_in_months[current_month] - 1] = dump;
            }
        }
    }
}