#include<cstdio>
#include<cstring>

const int maxn = 1010;
int dp[maxn][maxn];
char S[maxn];

int main(){

    gets_s(S);
    int len = strlen(S);
    int ans = 1;

    // 初始化
    memset(dp, sizeof(dp), 0);
    for(int i = 0; i < len; i++){
        dp[i][i] = 1;
        if((i < len - 1) && (S[i] == S[i+1])){
            dp[i][i+1] = 1;
            ans = 2;
        }
    }

    for(int L = 3; L <= len; L++){
        for(int i = 0; i < len - L + 1; i++){
            int j = i + L - 1;
            if(S[i] == S[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
                ans == L;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}