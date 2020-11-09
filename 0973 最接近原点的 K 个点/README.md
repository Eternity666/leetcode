## LeetCode 973. 最接近原点的 K 个点
本文总结了两个方法：
* 方法一为本人所使用的直接排序方法，简单易实现；
* 方法二使用了优先队列这一数据结构，耗时更短。

### 方法一：排序
重写`cmp()`函数，使用`sort()`进行直接排序。
#### 代码
```cpp
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), cmp);
        return {points.begin(), points.begin() + K};
    }
};
```
---


### 方法二：优先队列
>优先队列具有队列的所有特性，包括基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的，它和queue不同的就在于我们可以自定义其中数据的优先级, 让优先级高的排在队列前面,优先出队。
>而对于`pair`的队列，会先比较第一个元素，若第一个相等再比较第二个。

使用一个优先队列（大根堆）实时维护前 **K** 个最小的距离平方。
将前 **K** 个点的距离平方以及对应的编号（为了方便最后直接得到答案）放入优先队列中。
随后从第 **K+1** 个点开始遍历：如果当前点的距离平方比堆顶的点的距离平方要小，就把堆顶（**因为是大根堆**）的点弹出，再插入当前的点。
当遍历完成后，所有在优先队列中的点就是前 **K** 个距离最小的点。

不同的语言提供的优先队列的默认情况不一定相同。在 C++ 语言中，优先队列默认为大根堆。
#### 代码
```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < K; ++i) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        int n = points.size();
        for (int i = K; i < n; ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dist < q.top().first) {
                q.pop();
                q.emplace(dist, i);
            }
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};
```

**[原题传送门](https://leetcode-cn.com/problems/k-closest-points-to-origin/)**
