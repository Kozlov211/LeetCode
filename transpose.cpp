#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix_transpose(matrix[0].size(), vector<int> (matrix.size()));
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                matrix_transpose[j][i] = matrix[i][j];
            }
        }
        return matrix_transpose;
    }
};

int main() {

	return 0;
}
