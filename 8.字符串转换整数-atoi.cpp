/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include<string>
#include<limits.h>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Automaton{
    string state = "start";
    unordered_map<string,vector<string>> table = {
        {"start", {"start", "signed", "innumber", "end"}},
        {"signed",{"end",   "end",    "innumber", "end"}},
        {"innumber",{"end", "end", "innumber", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int get_col(char c){
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;
    void get(char c){
        state = table[state][get_col(c)];
        if(state == "innumber"){
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if(state == "signed"){
            sign = c == '+' ? 1 : -1;
        }
    }
};
class Solution {
public:
    int myAtoi(string s) {
        Automaton automaton;
        for(char c : s)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
// @lc code=end

