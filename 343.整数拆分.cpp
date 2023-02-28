/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int max(int a, int b){
        if(a > b)
            return a;
        return b;
    }

    int integerBreak(int n) {
        // int dp[n+1];
        vector<int> dp(n+1);
        // dp[0] = 1;
        // dp[1] = 1;
        dp[2] = 1;
        // dp[3] = 2;

        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i/2; j++){
                dp[i] = max(dp[i],max(j*(i-j), max(j * dp[i-j], dp[j]*dp[i-j])));
            }
        }
        return dp[n];
    }
};
// @lc code=end

