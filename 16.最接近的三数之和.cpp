/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<vector<int>> trilets;
        int closestNum = INT_MAX;
        int res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++){
            int first = nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while(front < back){
                int sum = first + nums[front] + nums[back];
                if(sum < target){
                    front++;
                    if(abs(sum - target) < closestNum){
                        closestNum = abs(sum - target);
                        res = sum;
                    }
                }

                else if(sum > target){
                    back --;
                    if(abs(sum - target) < closestNum){
                        closestNum = abs(sum - target);
                        res = sum;
                    }
                }
                else{
                    return target;
                }
            }

        }
        return res;
    }
};
// @lc code=end

