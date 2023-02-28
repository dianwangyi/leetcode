/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<string, map<string, int> > lines;
    vector<string> path;

    bool dfs(int ticketNum){
        if(ticketNum + 1== path.size()){
            return true;
        }

        string cur = path[path.size()-1];
        for(pair<const string, int>& line : lines[cur]){
            if(line.second > 0){
                path.emplace_back(line.first);
                line.second --;
                if(dfs(ticketNum)) return true;
                path.pop_back();
                line.second ++;
            }
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        lines.clear();
        for(vector<string> ticket : tickets){
            string start = ticket[0];
            string target = ticket[1];
            lines[start][target] ++;
        }

        path.emplace_back("JFK");
        dfs(tickets.size());
        return path;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<string> str = {"JFK","SFO"};
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};

    sol.findItinerary(tickets);
    return 0;
}
