/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include<string>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int minSize = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].length();
            minSize = min(minSize, len);
        }

        for(int i = 0; i < strs.size()-1; i++){
            for(int len = minSize; len >= 0; len--){
                if(strs[i].substr(0,len) == strs[i+1].substr(0,len)){
                    minSize = len;
                    break;
                }
            }
        }
        return strs[0].substr(0,minSize);
    }
};
// @lc code=end

