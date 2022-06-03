#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = (row > 0 ? matrix[0].size() : 0);
        matrix_ = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                matrix_[i][j] = matrix[i - 1][j - 1] + matrix_[i - 1][j] + matrix_[i][j - 1] -  matrix_[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return matrix_[row2 + 1][col2 + 1] - matrix_[row2 + 1][col1] - matrix_[row1][col2 + 1] + matrix_[row1][col1];
    }
private:
    vector<vector<int>> matrix_;
};


int main() {
	vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
	NumMatrix numMatrix(matrix);
	numMatrix.sumRegion(2, 1, 4, 3); 
	numMatrix.sumRegion(1, 1, 2, 2); 
	numMatrix.sumRegion(1, 2, 2, 4);
	return 0;
}
