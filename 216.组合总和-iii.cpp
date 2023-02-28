/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int> > res;

    void dfs(int start, int sum, int target, int n){
        if(path.size() == n){
            if(sum == target)
                res.push_back(path);
                return;
        }
        
        for(int i = start; i <= 9; i++){
            path.push_back(i);
            sum += i;
            dfs(i+1, sum, target, n);
            sum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        res.clear();
        dfs(1, 0, n, k);
        return res;
    }
};
// @lc code=end

