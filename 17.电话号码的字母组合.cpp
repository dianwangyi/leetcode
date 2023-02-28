/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
    string letters[10]={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    // string path = {};
    // vector<string> res;
public:
    // void dfs(string digits, int index){     // index 用于区分上下层  每一层对应的集合都不同
    //     if(path.size() == digits.size()){
    //         res.push_back(path);
    //         return;
    //     }
        
    //     int digit = digits[index] - '0';
    //     string letter = letters[digit];     // 计算当前层对应的集合

    //     for(int i = 0; i < letter.size(); i++){     // 在当前层中遍历添加一个值，进入下一层
    //         path.push_back(letter[i]);      // 遍历结束后当前层结束退出
    //         dfs(digits, index+1);
    //         path.pop_back();
    //     }
    // }

    string path;
    vector<string> res;

    void dfs(string &digits, int index)
    {
        if(path.size() == digits.size())
        {
            res.push_back(path);
            return;
        }

        int digit = digits[index] - '0';
        string letter = letters[digit];
        for(int i = 0; i < letter.size(); i++){
            path.push_back(letter[i]);
            dfs(digits, index + 1);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        dfs(digits, 0);
        return res;
    }
};
// @lc code=end

