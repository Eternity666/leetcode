
## LeetCode 452. 用最少数量的箭引爆气球
本题可使用贪心算法来解决~

---
### 贪心算法（先排序再取交集）
- 先按照区间左端点从小到大排序，再依次取交集，取不到交集就将计数器`res`加一；
- 到最后，虽然前面的区间都被计算了，但最后一个区间或最后一个取了交集的区间没有被计算在内，所以要再将计数器`res`加一；
- 因为每个气球被引爆的方式无外乎三种：
    - 和前面的气球同时被引爆；
    - 自己一个球被引爆；
    - 和后面的气球同时被引爆；

所以上述贪心算法一定可以找到全局最优解~

#### 代码
```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        int res = 0, cur = 1;
        while(cur < points.size()) {
            if(points[cur-1][1] < points[cur][0]) {
                res++;
                cur++;
            }
            else {
                points[cur][0] = max(points[cur-1][0], points[cur][0]);
                points[cur][1] = min(points[cur-1][1], points[cur][1]);
                cur++;
            }
        }
        return res + 1;
    }
};
```
---
### 延伸一个小问题
在写`sort()`的`cmp()`函数时发现，如果这样写
```cpp
sort(points.begin(), points.end(), [&](vector<int> a, vector<int> b) {
            return a[0] < b[0];
});
```
- 得到的运行结果为

|提交结果 | 运行时间 | 内存消耗 | 语言 |
|-----| -----|------ | ------|
| 通过 |	1684 ms	| 162.1 MB |	C++|

但如果这样写
```cpp
sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
});
```
- 得到的运行结果为

|提交结果 | 运行时间 | 内存消耗 | 语言 |
|-----| -----|------ | ------|
|通过	|312 ms|	34.4 MB|	C++|

**单单一个`&`的位置，就能让运行时间和内存消耗骤减！**

- 我的初步猜测：第二种方式通过引用来排序，所以时间和空间上的消耗较小~
- **但！** 我还缺一个科学的解释！
- **还望大佬能在评论区解答我的困惑！我将不胜感激！**

---
**[原题传送门](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/)**
