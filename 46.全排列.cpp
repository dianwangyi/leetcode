/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> nums, vector<bool> used){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true)
                continue;
            path.emplace_back(nums[i]);
            used[i] = true;
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        dfs(nums, used);
        return res;
    }
};
// @lc code=end

