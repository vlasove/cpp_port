#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void NewBus(map<string, vector<string>>& bus_and_stops, map<string, vector<string>>& stop_for_buses, string bus, const vector<string>& stops){
    bus_and_stops[bus] = stops;
    for(auto s : stops){
        if (stop_for_buses.count(s) == 0){
            stop_for_buses[s] = {bus};
        } else {
            stop_for_buses[s].push_back(bus);
        }
    }

}

void BusesForStop( map<string, vector<string>> stop_for_buses, string stop) {
    if(stop_for_buses.count(stop) == 0){
        cout << "No stop" << endl;
    } else {
        for(const auto& b : stop_for_buses[stop]){
            cout << b << " ";
        }
        cout << endl;
    }
}

void StopsForBus(map<string, vector<string>> bus_and_stops, map<string, vector<string>> stop_for_buses, string bus){
    if (bus_and_stops.count(bus) == 0){
        cout << "No bus" << endl;
    } else {
        auto current_stops = bus_and_stops[bus];
        for (const auto& stop : current_stops){
            if (stop_for_buses[stop].size() <= 1){
                cout << "Stop " << stop<<": no interchange"<<endl;
            } else {
                cout <<"Stop " << stop<<": ";
                for(auto b : stop_for_buses[stop]){
                    if (b != bus){
                        cout << b << " ";
                    }
                }
                cout <<endl;
            }
        }
    }
}

void AllBuses(map<string, vector<string>> bus_and_stops) {
    if (bus_and_stops.size() == 0){
        cout << "No buses" <<endl;
    } else {
        for(const auto& p : bus_and_stops) {
            cout << "Bus "<<p.first<<": ";
            for (const auto& s : p.second){
                cout << s << " ";
            }
            cout << endl;
        }
    }
    
}

int main(){
    map<string, vector<string>> bus_and_stops; // из номера автобуса в список остановок
    map<string, vector<string>> stop_for_buses; // из остановки в список номеров автобусов

    int n;
    cin >> n;
    for(int i =0; i < n; i++){
        string command;
        cin >> command;
        if(command == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;

            vector<string> stops;
            for(int j =0; j < stop_count; j++){
                string stop;
                cin >> stop;
                stops.push_back(stop);
            }
            NewBus(bus_and_stops, stop_for_buses, bus, stops);
        } else if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            BusesForStop(stop_for_buses, stop);
        } else if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            StopsForBus(bus_and_stops, stop_for_buses, bus);
        } else {
            AllBuses(bus_and_stops);
        }
    }
    return 0;
}