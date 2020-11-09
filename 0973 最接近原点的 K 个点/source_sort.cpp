//简单易实现的直接排序方法

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
