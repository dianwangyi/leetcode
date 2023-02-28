/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string res = "";
        int cycle = numRows * 2 - 2;
        for(int i = 0; i < numRows; i++){
            for(int j = i; j < s.length(); j += cycle){
                res += s[j];
                int secondJ = j - i + cycle - i;
                if(i != 0 && i != numRows - 1 && secondJ < s.length()){
                    res += s[secondJ];
                }
            }
        }
        return res;
    }
};
// @lc code=end

