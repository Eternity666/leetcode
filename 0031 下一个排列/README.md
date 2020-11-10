## LeetCode 31. 下一个排列
本文总结了两个方法：
* 方法一为直接使用STL库函数，简单易实现；
* 方法二使用了两次一维搜索，详细实现了本题算法。

### 方法一：排序
传说，C++ STL库中有着一个比较冷门的函数`next_permutation()`。
有了这个神奇的函数，这不有手就行？
直接一行代码给它干掉！
#### 代码
```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        
    }
};
```
---


### 方法二：两次一维搜索
思路同LeetCode官方题解，代码易懂~
#### 代码
```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation(nums.begin(), nums.end());
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if(i >= 0)
        {
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

**[原题传送门](https://leetcode-cn.com/problems/next-permutation/)**
