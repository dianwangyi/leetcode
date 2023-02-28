/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        unordered_set<int> uset;
        for(int i = 0; i < nums.size(); i++){
            // if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            //     continue;
            if(used[i] == true)
                continue;
            if(uset.find(nums[i]) != uset.end())
                continue;
            uset.insert(nums[i]);
            used[i] = true;
            path.emplace_back(nums[i]);
            dfs(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        // vector<bool> colused(nums.size(), false);
        // sort(nums.begin(), nums.end());
        dfs(nums, used);
        return res;
    }
};
// @lc code=end

