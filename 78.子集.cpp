/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(int start, vector<int>& nums){
        res.emplace_back(path);
        if(start >= nums.size())
        {
            return;
        }

        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(i+1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        // path.push_back("");
        dfs(0, nums);
        return res;

    }
};
// @lc code=end

