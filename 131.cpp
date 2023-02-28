/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    bool notHui(string str){
        int n = str.size();
        for(int l = 0, r = n-1; l < r; l++, r--){
            if(str[l] != str[r])
                return true;
        }
        return false;
    }

    void dfs(string& s, int start){
        if(start >= s.size()){
            res.emplace_back(path);
            return;
        }
        
        for(int i = start; i < s.size(); i++){
            if(notHui(s.substr(start, i-start+1)))
                continue;
            path.push_back(s.substr(start, i-start+1));
            dfs(s, i+1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        dfs(s, 0);
        return res;
    }
};

// @lc code=end

