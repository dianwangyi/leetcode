/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <math.h>
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (((dividend ^ divisor)>>31 & 0x1) == 1)?-1:1;
        long dd = abs((long)dividend);
        long ds = abs((long)divisor);
        long res = 0;
        long sum = 0;

        while(sum + ds <= dd){
            long i = 1;
            long tmp = ds;
            while(sum + tmp <= dd){
                sum += tmp;
                res += i;
                i = i << 1;
                tmp = tmp << 1;
            }
        }
        
        res *= sign;
        if(res > INT_MAX || res < INT_MIN)
            return INT_MAX;
        return (int) res;
    }
};
// @lc code=end
