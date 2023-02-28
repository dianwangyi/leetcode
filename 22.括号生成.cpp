/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include<vector>
#include<string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> res;
    void backTrack(int open, int close, string cur, int n){
        if(cur.length() == 2*n){
            res.push_back(cur);
            return;
        }
        if(open < n) backTrack(open+1, close, cur+"(", n);
        if(close < open) backTrack(open, close+1, cur+")", n);
    }
    vector<string> generateParenthesis(int n) {
        backTrack(0, 0, "", n);
        return res;
    }
};
// @lc code=end

