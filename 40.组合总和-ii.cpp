/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& candidates, int target, int sum, int start, vector<bool>& used) {
        if(sum == target){
            res.push_back(path);
            return;
        }
        
        for(int i = start; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == true)
                continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = false;
            dfs(candidates, target, sum, i+1, used);
            used[i] = true;
            sum -= candidates[i];
            path.pop_back();
        }
        
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), true);
        path.clear();
        res.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, used);
        return res;
    }
};

// @lc code=end

