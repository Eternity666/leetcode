class Solution {
public:

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        for(int i = 0; i < arr2.size(); i++)
        {
            m[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if(m.count(a) && m.count(b)) {
                return m[a] < m[b];
            }
            else if(m.count(a) && !m.count(b)){
                return true;
            }
            else if (!m.count(a) && m.count(b)) {
                return false;
            }
            else {
                return a < b;
            }
        });
        return arr1;
    }
};
