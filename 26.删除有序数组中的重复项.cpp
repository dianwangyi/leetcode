/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        while(j < nums.size()){
            if(nums[j] != nums[j-1]){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};
// @lc code=end

