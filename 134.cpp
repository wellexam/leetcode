#include "regular_headers.hpp"

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int current_gas = 0;
    int start_pos = 0;
    int n = gas.size();

    int i = 0;

    while (i < n) {
        int count = 0;
        int current_gas = 0;
        int current_pos = i;
        while (true) {
            current_gas += gas[current_pos];
            if (current_gas - cost[current_pos] < 0) {
                break;
            }
            count++;
            current_gas -= cost[current_pos];
            current_pos = (current_pos + 1) % n;
            if (count == n) {
                return i;
            }
        }
        i = i + count + 1;
    }
    return -1;
}

int main() {
    vector<int> gas{2, 3, 4};
    vector<int> cost{3, 4, 3};
    cout << canCompleteCircuit(gas, cost);
    return 0;
}