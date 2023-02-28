/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        vector<int> tab;
        while(x){
            int temp = x % 10;
            tab.push_back(temp);
            x = x / 10;
        }
        vector<int>::iterator itFor = tab.begin(), itBack = tab.end()-1;
        for(; itFor < itBack; itFor++, itBack--){
            if(*itFor != *itBack) return false;
        }
        return true;
    }
};
// @lc code=end

