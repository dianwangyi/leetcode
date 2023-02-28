/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <vector>
#include <string.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int columns[9][9];
        int subboxes[3][3][9];

        memset(rows,0,sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(subboxes, 0, sizeof(subboxes));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c != '.'){
                    int index = c -'0' - 1;
                    rows[i][index] ++;
                    columns[j][index] ++;
                    subboxes[i/3][j/3][index] ++;
                    if(rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i/3][j/3][index] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
// int table[9] = {0};
//     void cleanTable()
//     {
//         for(int i = 0; i < 9; i++){
//             table[i] = 0;
//         }
//     }
//     bool checkEmpty(){
//         for(int i = 0; i < 9; i++){
//             if(table[i] != 0)
//                 return false;
//         }
//         return true;
//     }
// int index;
//         for(int i = 0; i < 9; i++){
//             for(int j = 0; j < 9; j++){
//                 if(board[i][j] == '.')
//                     continue;
//                 index = board[i][j] - '1';
//                 table[index] ++;
//                 if(table[index] > 1) return false;
//             }
//             // if(checkEmpty())
//             //     return false;
//             cleanTable();
//         }    

//         for(int j = 0; j < 9; j++){
//             for(int i = 0; i < 9; i++){
//                 if(board[i][j] == '.')
//                     continue;
//                 index = board[i][j] - '1';
//                 table[index] ++;
//                 if(table[index] > 1) return false;
//             }
//             // if(checkEmpty())
//             //     return false;
//             cleanTable();
//         }

//         for(int k = 0; k < 9; k+=3){
//             for(int m = 0; m < 9; m+=3){
//                 for(int i = 0; i < 3; i++){
//                     for(int j = 0; j < 3; j++){
//                         if(board[i+k][j+m] == '.')
//                             continue;
//                         index = board[i+k][j+m] - '1';
//                         table[index] ++;
//                         if(table[index] > 1) return false;
//                     }
//                 }
//                 cleanTable();
//             }
//         }
//         return true;
// ["5","3",".",".","7",".",".",".","."],
// ["6",".",".","1","9","5",".",".","."],
// [".","9","8",".",".",".",".","6","."],
// ["8",".",".",".","6",".",".",".","3"],
// ["4",".",".","8",".","3",".",".","1"],
// ["7",".",".",".","2",".",".",".","6"],
// [".","6",".",".",".",".","2","8","."],
// [".",".",".","4","1","9",".",".","5"],
// [".",".",".",".","8",".",".","7","9"]]

// [".",".",".",".","5",".",".","1","."],
// [".","4",".","3",".",".",".",".","."],
// [".",".",".",".",".","3",".",".","1"],
// ["8",".",".",".",".",".",".","2","."],
// [".",".","2",".","7",".",".",".","."],
// [".","1","5",".",".",".",".",".","."],
// [".",".",".",".",".","2",".",".","."],
// [".","2",".","9",".",".",".",".","."],
// [".",".","4",".",".",".",".",".","."]]

