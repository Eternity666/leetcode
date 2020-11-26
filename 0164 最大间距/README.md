## LeetCode 164. 最大间距
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
如果数组元素个数小于 2，则返回 0。
##### 示例 1：
```
输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
```
##### 示例 2：
```
输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
```
##### 说明：
- 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
- 请尝试在**线性**时间复杂度和空间复杂度的条件下解决此问题。

---

## 解题思路分享
本文总结了两个方法：
* 方法一：~~什么是时间复杂度~~法（~~管他三七二十一，直接`sort`！~~ 执行用时可以打败51%）
* 方法二借鉴官方题解的思路，使用桶排序

**建议学习第二种解法，对自己有提升的意义！**

---
### 方法一：~~什么是时间复杂度~~法
- 先将数组`sort`一下，再遍历一遍数组寻找最大间距
- 因为用了STL中的`sort()`函数，所以算法复杂度为O(nlogn)

#### 代码
```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int max_difference = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i+1] - nums[i] > max_difference)
                max_difference = nums[i+1] - nums[i];
        }
        return max_difference;
    }
};
```
---


### 方法二：桶排序
- 试想一个特殊的序列：
```
0 5 10 15 20 25 30
```
- 这个序列有7个元素，6个间隔，最大间隔肯定是5
- 那么，如果这个序列没这么特殊，那么最大间隔肯定会大于5！
- 所以我们就设法让最大间距只会出现在桶与桶之间！
- 因此，我们选择整数`interval = ⌊(max-min) / (n-1)⌋`。然后将整个区间划分为至少`(max-min) / interval + 1`个桶（不然桶内的最大间距就大于interval了）
- 根据前面的结论，我们知道现在元素之间的最大间距一定不会出现在某个桶的内部，而一定会出现在不同桶当中。
- 最后，在找出每个元素所在的桶之后，我们可以维护每个桶内元素的最大值与最小值。只需遍历比较相邻的桶，用后一个桶的最小值与前一个桶的最大值之差作为两个桶的间距，就能得到最大间距。


利用这一思想，代码如下~


#### 代码
```cpp
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
```

**[原题传送门](https://leetcode-cn.com/problems/maximum-gap/)**
