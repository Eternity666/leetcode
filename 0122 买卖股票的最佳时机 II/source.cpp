class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int money = 0;
        for(int i = 0; i < prices.size() - 1; i++)
        {
            if(prices[i] < prices[i+1])
                money += prices[i+1] - prices[i];
        }
        return money;
    }
};
