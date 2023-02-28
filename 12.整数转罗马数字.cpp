/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    string intToRoman(int num) { 
        string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                           {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                           {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                           {"", "M", "MM", "MMM"}};
        string res;
        int step = 0;
        while(num){
            int temp = num % 10;
            res = table[step][temp] + res;
            num /= 10;
            step ++;
        }
        return res;
    }
};
// @lc code=end

