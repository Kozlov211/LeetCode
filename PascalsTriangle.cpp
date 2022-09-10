namespace Pascal_Triangle {

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; ++i) {
            result[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }
        return result;
    }
};

void Tests() {
    Solution solution;
    {
        vector<vector<int>> ans = {{1}};
        assert(solution.generate(1) == ans);
    }
    {
        vector<vector<int>> ans = {{1}, {1, 1}};
        assert(solution.generate(2) == ans);
    }
    {
        vector<vector<int>> ans = {{1}, {1, 1}, {1,2,1}};
        assert(solution.generate(3) == ans);
    }
    {
        vector<vector<int>> ans = {{1}, {1, 1}, {1,2,1}, {1,3,3,1}};
        assert(solution.generate(4) == ans);
    }

}
