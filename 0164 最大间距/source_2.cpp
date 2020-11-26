class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int len = nums.size();

        int min_value = *min_element(nums.begin(), nums.end());
        int max_value = *max_element(nums.begin(), nums.end());
        int interval = max(1, (max_value - min_value) / (len - 1));
        int num_buckets = (max_value - min_value) / interval + 1;

        vector<pair<int, int> > buckets(num_buckets, {-1, -1}); 
        //借鉴官方题解的思想，buckets存储每个桶的最小值、最大值，(-1, -1) 表示该桶为空
        for(int i = 0; i < len; i++) {
            int index = (nums[i] - min_value) / interval;
            if(buckets[index].first == -1) {
                buckets[index].first = nums[i];
                buckets[index].second = nums[i];
            }
            else {
                buckets[index].first = min(buckets[index].first, nums[i]);
                buckets[index].second = max(buckets[index].second, nums[i]);
            }
        }

        int max_interval = 0, pre = -1;
        for(int i = 0; i < num_buckets; i++) {
            if(buckets[i].first == -1)
                continue;
            if(pre != -1) {
                max_interval = max(max_interval, buckets[i].first - buckets[pre].second);
            }
            pre = i;
        }
        return max_interval;
    }
};
