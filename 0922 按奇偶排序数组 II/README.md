## LeetCode 922. 按奇偶排序数组 II
本文总结了三个易理解的方法：
* 方法一为博主使用的方法，根据原始思路进行逐步编码；
* 方法二为方法一的简化版，将两个二重循环合并为一个；
* 方法三新建一个数组，用两次一重循环解决。

### 方法一：原始思路
**第一层循环**：寻找不配坐在现有位置上的元素（`i`和`A[i]`奇偶性不同）
**第二层循环**：从`i+1`开始查找，找到第一个同样不配坐在现有位置上的元素，将两者位置互换。
因为需要换位置的元素总是**成对**出现，所以循环在最后一定可以完美结束！
#### 代码
```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i = 0; i < A.size(); i++)
        {
            if(i % 2 == 0 && A[i] % 2 != 0)
            {
                for(int j = i + 1; j < A.size(); j++)
                {
                    if(j % 2 != 0 && A[j] % 2 == 0)
                    {
                        swap(A[i], A[j]);
                        break;
                    }
                }
            }
            else if (i % 2 != 0 && A[i] % 2 == 0)
            {
                for(int j = i + 1; j < A.size(); j++)
                {
                    if(j % 2 == 0 && A[j] % 2 != 0)
                    {
                        swap(A[i], A[j]);
                        break;
                    }
                }
            }
        }
        return A;
    }
};
```
---


### 方法二：方法一的巧妙简化
为数组的偶数下标部分和奇数下标部分分别维护指针`i`和`j`。在每一步中，如果`A[i]`为奇数，则不断地向前移动`j`（每次移动两个单位），直到遇见下一个偶数。此时，可以直接将 `A[i]` 与 `A[j]` 交换。
不断进行这样的过程，最终能够将所有的整数放在正确的位置上。
#### 代码
```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int j = 1;
        for (int i = 0; i < n; i += 2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1) {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
        }   
        return A;
    }
};
```
---


### 方法三：另辟结果数组
另辟`res`数组
**第一次**：遍历一遍原始数组把所有的偶数放进 `res[0]`，`res[2]`，`res[4]`，`...`

再遍历一遍数组把所有的奇数依次放进 `res[1]`，`res[3]`，`res[5]`，依次类推。

#### 代码
```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);

        int i = 0;
        for (int x: A) {
            if (x % 2 == 0) {
                ans[i] = x;
                i += 2;
            }
        }
        i = 1;
        for (int x: A) {
            if (x % 2 == 1) {
                ans[i] = x;
                i += 2;
            }
        }
        return ans;
    }
};
```


**[原题传送门](https://leetcode-cn.com/problems/sort-array-by-parity-ii/)**
