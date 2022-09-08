namespace Largest_Number_At_Least_Twice_of_Others {

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first_max = *nums.begin();
        int second_max = *(nums.begin() + 1);
        size_t first_max_index = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > first_max) {
                second_max = first_max;
                first_max = nums[i];
                first_max_index = i;
            } else if (nums[i] > second_max && nums[i] != first_max) {
                second_max = nums[i];
            }
        }
        return first_max >= second_max * 2 ? first_max_index : -1;

    }
};

void Tests() {
    Solution solution;
    {
        vector<int> nums = {3,6,1,0};
        assert(solution.dominantIndex(nums) == 1);
    }
    {
        vector<int> nums = {1,2,3,4};
        assert(solution.dominantIndex(nums) == -1);
    }
    {
        vector<int> nums = {1,4};
        assert(solution.dominantIndex(nums) == 1);
    }
    {
        vector<int> nums = {4,1};
        assert(solution.dominantIndex(nums) == 0);
    }
    {
        vector<int> nums = {4,4};
        assert(solution.dominantIndex(nums) == -1);
    }
}

}
