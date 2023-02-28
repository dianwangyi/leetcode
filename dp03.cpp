#include<cstdio>

const int maxn = 1010;
const int INF = 0x3fffffff;
int G[maxn][maxn];
int dp[maxn];
int m, n;
int choice[maxn];

int DP(int i){
    if(dp[i] > 0) return dp[i];

    for(int j = 0; j < n; j++){
        if(G[i][j] != INF){
            int temp = DP(j) + G[i][j];
            if(temp > dp[i]){
                dp[i] = temp;
                choice[i] = j;
            }
        }
    }
}
