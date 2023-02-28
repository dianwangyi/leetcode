/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int searchLow(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0, r = n-1;
        int mid;
        // 找leftindex <= target
        while(l <= r){
            mid = l + (r-l)/2;
            if(target <= nums[mid])
                r = mid - 1;
            else   
                l = mid + 1;
        }
        return l;
    }

    int searchHigh(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0, r = n-1;
        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] <= target)
                l = mid + 1;
            else    //target < nums[mid]
                r = mid - 1;
        }
        return r;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = searchLow(nums, target);
        int high = searchHigh(nums, target);
        if(low == nums.size() || nums[low] != target) return vector<int>{-1,-1};
        return vector<int> {low, high};
    }
};
// @lc code=end


// int n = nums.size();
//         vector<int> res;
//         int flag = 0;
//         if(n == 1 && nums[0] == target)
//             return vector<int>{0,0};
//         if(n <= 1)
//             return vector<int>{-1,-1};

//         // 二分查找 target
//         int l = 0, r = n-1;
//         int mid;
//         while(l <= r){
//             mid = (l + r) / 2;
//             if(nums[mid] == target){
//                 flag = 1;
//                 break;
//             }

//             if(target < nums[mid])
//                 r = mid - 1;
             
//             else
//                 l = mid + 1;
//         }

        
//         // 未找到，返回[-1.-1]

//         // 找到，向左右扩展，直到不等于target
//         if(flag == 1){
//             int left = mid, right = mid;
//             while(left >= 0 && nums[left] == nums[mid])
//                 left --;
//             while(right <= n-1 && nums[right] == nums[mid])
//                 right++;
            
//             return vector<int>{left+1,right-1};
//         }
//         else{
//             return vector<int>{-1,-1};
//         }
