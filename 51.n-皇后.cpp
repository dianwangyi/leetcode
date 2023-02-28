/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    // string line;
    vector<string> board;
    vector<vector<string>> res;

    bool checkBoard(int n, int row, int col, vector<string>& board){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q')
                return false;
        }
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--,j--){
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void dfs(int n, int row, vector<string>& board){
        if(row == n){
            res.push_back(board);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if( ! checkBoard(n, row, i, board))
                continue;
            board[row][i] = 'Q';
            dfs(n, row+1, board);
            board[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        // string line(n, '.');
        dfs(n, 0, board);
        return res;
    }
};
// @lc code=end

