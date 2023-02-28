/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[2];
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= n; i++){
            int d = min(dp[1]+cost[i-1], dp[0]+cost[i-2]);
            dp[0] = dp[1];
            dp[1] = d;
        }

        return dp[1];
    }
};

// @lc code=end


