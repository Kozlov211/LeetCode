namespace Triangle {

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp {triangle[triangle.size() - 1]};
        for (int row = triangle.size() - 2; row >= 0; row--) {
            for (size_t colom = 0; colom < triangle[row].size(); ++colom) {
                dp[colom] = min(dp[colom], dp[colom + 1]) + triangle[row][colom];
            }
        }
        return dp[0];
    }
};

void Tests() {
    Solution solution;
    {
        vector<vector<int>> triangle {{-10}};
        assert(solution.minimumTotal(triangle) == -10);
    }
    {
        vector<vector<int>> triangle {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
        assert(solution.minimumTotal(triangle) == 11);
    }
    {
        vector<vector<int>> triangle {{2}, {2, 4}, {2, 5, 7}, {2, 1, 8, 3}};
        assert(solution.minimumTotal(triangle) == 7);
    }
    {
        vector<vector<int>> triangle {{-1}, {2, 3}, {1, -1, -3}};
        assert(solution.minimumTotal(triangle) == -1);
    }

}

}

