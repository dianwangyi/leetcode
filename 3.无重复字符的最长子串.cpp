/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<string>
using namespace std;
// @lc code=start
#include<unordered_set>
#include<algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int rk = -1, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(i != 0){
                uset.erase(s[i-1]);
            }
            while(rk + 1 < s.size() && uset.count(s[rk+1]) == 0){
                uset.insert(s[rk+1]);
                rk ++;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
// @lc code=end

