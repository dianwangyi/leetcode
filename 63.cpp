#include <vector>
#include <iostream>

using namespace std;

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
            cout << dp[j] <<" ";
        }
        cout << "\n" ;
    }

    return dp.back();
}

int main()
{
    vector<vector<int>> obstacleGrid={{0,0,0},{0,1,0},{0,0,0}};
    int res = uniquePathsWithObstacles(obstacleGrid);
    printf("%d\n", res);
    return 0;
}