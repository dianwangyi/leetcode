/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include<string>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int maxL = 1;
        string res;
        vector<vector<int>> dp(len, vector<int>(len));
        for(int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
            if(i > 0 && s[i-1] == s[i]){
                dp[i-1][i] = 2;
                maxL = 2;
                res = s.substr(i-1,2);
            }
        }

        for(int l = 3; l <= len; l++){
            for(int i = 0; i < len - l + 1; i++){
                if(s[i] == s[i+l-1] && dp[i+1][i+l-2]){
                    dp[i][i+l-1] = l;
                    maxL = max(maxL, l);
                    res = s.substr(i, l);
                }
                
            }
        }
        if(maxL == 1) return s.substr(0,1);
        return res;
    }
};
// @lc code=end

