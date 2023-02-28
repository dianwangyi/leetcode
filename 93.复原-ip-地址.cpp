/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> res;

    bool isValid(const string& str){
        if(str.size() == 0) 
            return false;
        int count = 0;
        if(str.size() > 1 && str[0] == '0')
            return false;
        for(int i = 0; i < str.size(); i++){
            if(str[i] > '9' || str[i] < '0')
                return false;
            count *= 10;
            count += str[i] - '0';
            if(count > 255)
                return false;
        }
        return true;
    }

    void dfs(string s, int start, int pointNum){
        if(pointNum == 3){
            if(isValid(s.substr(start)))
                res.emplace_back(s);
            return;
        }

        for(int i = start; i < s.size(); i++){
            string sstr = s.substr(start, i-start+1);
            if(! isValid(sstr))
                continue;
            s.insert(i+1,".");
            dfs(s, i + 2, pointNum + 1);
            s.erase(i+1, 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s.size() < 4 || s.size() > 12) 
            return res;
        dfs(s, 0, 0);
        return res;
    }
};
// @lc code=end

