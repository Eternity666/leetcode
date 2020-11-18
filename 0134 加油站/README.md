## LeetCode 134. 加油站
本文总结了两个方法：
* 方法一为博主所使用的方法，暴力求解；
* 方法二为方法一的优化版，同LeetCode官方题解，作为学习资料，总结在这里。

### 方法一：暴力求解
以每个加油站为起点，尝试计算能否跑完一圈：如果可以就直接返回该起点；如果不可以就继续以下一个加油站为起点进行搜索。
我自认为代码非常简单易懂~
#### 代码
```cpp
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
```
---


### 方法二：一次遍历
* 该题解的目标是通过减小被检查的加油站数目，来降低总的时间复杂度。
* 考虑从加油站 `x` 出发，每经过一个加油站就加一次油，第一个无法到达的加油站是 `y`（不妨设 `x<y`）；
* 通过简单的数学证明，可以得到从 `x, y` 之间的任何一个加油站出发，都无法到达加油站 `y`；
* **因此**，我们可以利用这一点，首先检查第 `0` 个加油站，并试图找到第一个无法到达的加油站 `i`；如果能找到，下一次就从加油站 `i+1` 开始检查。
* 最终，数组只被遍历了一次。

#### 代码
```cpp
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


```

_**[原题传送门](https://leetcode-cn.com/problems/gas-station/)**_
