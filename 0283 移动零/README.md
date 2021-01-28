## LeetCode 283. 移动零
本文总结了两个方法：
* 方法一为替换法；
* 方法二利用两个指针进行位置互换操作；

### 方法一：替换法
- 从左向右遍历，遇到第一个不为0的数，将其直接移动到第一位；遇到第二个不为0的数，就将其移动到第二位；以此类推~
- 遍历完后，将后面没有被替换的位置全部用0代替。

#### 代码
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0, len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }
        for(int i = index; i < len; i++)
        {
            nums[i] = 0;
        }
    }
};
```
---


### 方法二：双指针实现 O(n)
- 将序列看作由两部分组成：已处理序列和未处理序列；
- 用左指针`left`指向当前已处理序列的尾部，右指针`right`指向待处理序列的头部；
- 让右指针不断向右移动，每当右指针指向非零数，则将左右指针对应的数交换，同时左指针右移一位。

如此做，每次交换都将左指针的零与右指针的非零数交换，而且非零数的相对顺序并未改变。

所以，左指针左边均为非零数、右指针左边直到左指针处均为零。


#### 代码
```cpp
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
```

_**[原题传送门](https://leetcode-cn.com/problems/move-zeroes/)**_
