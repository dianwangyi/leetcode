#include <vector>
#include <iostream>

using namespace std;

void bag2()
{
    vector<int> weight = {1,3,4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    vector<vector<int>> dp(weight.size(), vector<int>(bagweight+1,0));

    for(int j = weight[0]; j <= bagweight; j++){
        dp[0][j] = value[0];
    }

    for(int i = 1; i < weight.size(); i++){
        for(int j = 0; j <= bagweight; j++){
            if(j < weight[i]) 
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
    }

    cout << dp[weight.size()-1][bagweight] << endl;
}

void bag1(){
    vector<int> weight = {1,3,4};
    vector<int> value ={15,20,30};
    int bagweight = 4;

    vector<int> dp(bagweight+1, 0);
    for(int i = 0; i < weight.size(); i++){
        for(int j = bagweight; j >= weight[i]; j--){
            dp[j] = max(dp[j],dp[j-weight[i]] + value[i]);
        }
    }
    
    cout << dp[bagweight] << endl;
}

int main()
{

    bag2();
    bag1();
    return 0;
}