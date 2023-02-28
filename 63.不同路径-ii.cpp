/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        vector<int> dp(n);

        dp[0] = (obstacleGrid[0][0] == 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    continue;
                }

                if(j-1 >= 0 && obstacleGrid[i][j-1] == 0)
                    dp[j] += dp[j-1];
            }
        }

        return dp.back();
    }
};
// @lc code=end

