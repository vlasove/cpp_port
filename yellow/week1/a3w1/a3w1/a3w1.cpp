#include <map>
#include <tuple>
#include <vector>


using namespace std;


int FindMaxRepetitionCount(const vector<Region>& regions) {
    map<Region, int> repetitions;
    int result;
    for (const auto& r : regions) {
        result = max(result, ++repetitions[r]);
    }
    return result;
}

bool operator <(const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

