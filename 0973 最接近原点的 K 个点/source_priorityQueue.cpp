//优先队列方法

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
