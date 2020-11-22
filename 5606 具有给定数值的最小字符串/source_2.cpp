class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for (int i = n; i >= 1; --i) {
            int u = k - (i - 1) * 26;
            if (u > 0) {
                ans += char(u + 96);
                k -= u;
            }
            else {
                ans += 'a';
                --k;
            }
        }
        return ans;
    }
};
