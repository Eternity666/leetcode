class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sum_gas = 0, sum_cost = 0;
            int count = 0;
            while (count < n) {
                int j = (i + count) % n;
                sum_gas += gas[j];
                sum_cost += cost[j];
                if (sum_cost > sum_gas) {
                    break;
                }
                count++;
            }
            if (count == n) {
                return i;
            } else {
                i = i + count + 1;
            }
        }
        return -1;
    }
};
