class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size(), left = 0, right = 0;
        while (right < len) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
