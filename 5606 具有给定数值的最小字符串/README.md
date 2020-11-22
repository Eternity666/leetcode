
## LeetCode 5606. 具有给定数值的最小字符串（第216场周赛第2题）
本文总结了两个方法：
* 方法一为累加法；
* 方法二使用减法构造字符串；

这两种方法本质上都是贪心思想~

---
### 方法一：累加法
- 首先将结果字符串`res`初始化为`"aa...a"`，然后从后向前依次加1，当一位加到`z`后再换到前一位继续加，直到`res`对应的数与`k`相等，结束遍历，输出即可~

#### 代码
```cpp
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
```
---


### 方法二：利用差值构造
- 对某一位字符来说，假设其为`a`，如果后面的字符均用`z`，对应的数大于等于`k`，那么这一位一定要放`a`；
- 还是对这一位字符来说，假设其为`a`，如果后面的字符均用`z`，但对应的数小于`k`了，那么这一位就要用
<center><b><big> k - 26 × 后面的字符位数 </big></b></center>
 对应的小写字母来代替；

利用这一思想，代码如下~


#### 代码
```cpp
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
```
---
**[原题传送门](https://leetcode-cn.com/problems/smallest-string-with-a-given-numeric-value/)**

###### 我的CSDN博客原文~
[https://blog.csdn.net/weixin_42989041/article/details/109958307](https://blog.csdn.net/weixin_42989041/article/details/109958307)
