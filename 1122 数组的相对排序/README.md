## LeetCode 1122. 数组的相对排序
本文总结了两个方法：
* 方法一为博主使用的方法，傻瓜式重写`cmp()`函数；
* 方法二使用了计数排序的思想，同LeetCode官方题解，写下来巩固一下~

### 方法一：重写`cmp()`
之所以叫傻瓜式，因为我在cmp中把四种情况都列了出来，代码虽然清晰但并不是特别简洁~
#### 代码
```cpp
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
```

---

### 方法二：计数排序
官方解释：
>https://leetcode-cn.com/problems/relative-sort-array/solution/shu-zu-de-xiang-dui-pai-xu-by-leetcode-solution/
#### 代码
```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int upper = *max_element(arr1.begin(), arr1.end());
        vector<int> frequency(upper + 1);
        for (int x: arr1) {
            ++frequency[x];
        }
        vector<int> ans;
        for (int x: arr2) {
            for (int i = 0; i < frequency[x]; ++i) {
                ans.push_back(x);
            }
            frequency[x] = 0;
        }
        for (int x = 0; x <= upper; ++x) {
            for (int i = 0; i < frequency[x]; ++i) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/relative-sort-array/solution/shu-zu-de-xiang-dui-pai-xu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```


**[原题传送门](https://leetcode-cn.com/problems/relative-sort-array/)**
