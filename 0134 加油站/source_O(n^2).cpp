class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++)
        {
            //以每个加油站为起点进行遍历
            int sum = 0, num = 0;
            int tmp = i;
            while(num < n)
            {
                sum = sum + gas[tmp % n] - cost[tmp % n];
                if(sum < 0) {
                    break;
                }
                num++;
                tmp++;
            }
            if(num == n)
                return i;
            else
                continue;
        }
        return -1;
    }
};
