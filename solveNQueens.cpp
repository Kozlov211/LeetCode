#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<string>> chessboard;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return chessboard;
    }
    
    bool check(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            if(board[i][col] == 'Q') {
                return false;  
            } 
            if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') {
                return false;
            }
            if (row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') {
                return false;
            }
            if (row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') {
                return false;
            }
            if (row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') {
                return false;
            }
	    }
	    return true;
    }
    
    void solve(vector<string>& board, int row) {
        if (board.size() == row) {
            chessboard.push_back(board);
            return;
        }
        for(int col = 0; col < board.size(); ++col) {
            if (check(board, row, col)) {
                board[row][col] = 'Q';
                solve(board, row + 1);
                board[row][col] = '.';
            }
        }
    }
};

int main() {

	return 0;
}
