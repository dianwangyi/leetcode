/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include<limits.h>
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x)
        {
            if(res > INT_MAX / 10 || res < INT_MIN / 10){
                return 0;
            }
            int num = x % 10;
            res = res * 10 + num;
            x = x / 10;
        }
        return res;
    }
};
// @lc code=end

