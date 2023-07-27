class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        Permute(result, nums, used, {});
        return result;
    }

    void Permute(vector<vector<int>>& result, const vector<int>& nums, vector<bool>& used, vector<int> curr) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        for (uint32_t i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                curr.push_back(nums[i]);
                Permute(result, nums, used, curr);
                curr.pop_back();
                used[i] = false;
            }
        }
    }
};

void Tests() {
    Solution solution;
    {
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> ans = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
        assert(solution.permute(nums) == ans);
    }
    {
        vector<int> nums = {0, 1};
        vector<vector<int>> ans = {{0, 1}, {1, 0}};
        assert(solution.permute(nums) == ans);
    }
    {
        vector<int> nums = {0};
        vector<vector<int>> ans = {{0}};
        assert(solution.permute(nums) == ans);
    }
    cout << "Tests passed" << endl;
}

}
