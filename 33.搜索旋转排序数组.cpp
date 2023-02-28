/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        if(!n) return -1;
        if(n == 1)
            return nums[0] == target ? 0 : -1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] >= nums[l]){   //左边升序
                if(target < nums[mid] && target >= nums[l]){
                    r = mid - 1;
                }else
                    l = mid + 1;
            }else{
                if(target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else   
                    r = mid - 1;
            }
        }
        return -1;        
    }
};
// @lc code=end

        // int n = (int)nums.size();
        // if(!n) return -1;
        // if(n == 1) 
        //     return nums[0] == target ? 0 : -1;
        
        // int l = 0, r = n-1;
        // while(l <= r){
        //     int mid = (l + r) / 2;
        //     if(nums[mid] == target)
        //         return mid;

        //     if(nums[l] <= nums[mid]){ //左边是正常
        //         if(nums[l] <= target && target < nums[mid])
        //             r = mid - 1;
        //         else 
        //             l = mid + 1;
        //     }
        //     else{
        //         if(nums[mid] < target && target <= nums[r])
        //             l = mid + 1;
        //         else   
        //             r = mid - 1;
        //     }
        // }
        // return -1;