class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            res += "a";
            cnt++;
        }
        int pos = 1;
        while(k > cnt) {
            if(res[n - pos] == 'z') {
                pos++;
            }
            res[n - pos]++;
            k--;
        }
        return res;
    }
};
