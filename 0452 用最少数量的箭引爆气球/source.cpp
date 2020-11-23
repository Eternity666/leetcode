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
