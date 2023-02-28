/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
#include <algorithm>

using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& candidates, int start, int sum, int target){
        if(sum > target)
            return;
        if(sum == target){
            res.push_back(path);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, i, sum, target);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        dfs(candidates,0,0,target);
        return res;
    }
};
// @lc code=end

