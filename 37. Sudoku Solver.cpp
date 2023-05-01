/* Problem Link: https://leetcode.com/problems/sudoku-solver/description/
Solution Link: https://leetcode.com/problems/sudoku-solver/solutions/3474437/c-solution-with-comments-backtracking/

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution. */
//code
class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char ch){
        int n = board.size();
        for(int i = 0; i<n; i++){
            if(board[row][i] == ch)return false;
            if(board[i][col] == ch)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == '.'){ //if the current cell is empty, we need to fill this
                    //and it can be filled with characters from 1 to 9
                    for(char it='1'; it<='9'; it++){
                        if(isSafe(i,j,board,it)){ //if the char we are putting is valid
                            board[i][j] = it;

                            bool checkNext = solve(board);
                            //if the next answer is also valid then we can return true and proceed to fill other blank cells
                            if(checkNext)return true;
                            //otherwise we have to backtrack as we have put wrong character in the cell
                            else board[i][j] = '.';
                        }

                    }
                    return false; //if no char can be put at the current position,we will return false;
                }
            }
        }
        return true; //if we successfully would be able to fill all the blank spaces then we will return true.
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
