namespace Jump_Game {

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int min_jump = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            ++min_jump;
            if (nums[i] >= min_jump) {
                min_jump = 0;
            }
        }
        return min_jump == 0 ? true : false;
    }
};

void Tests() {
    Solution solution;
    {
        vector<int> nums {2};
        assert(solution.canJump(nums) == true);
    }
    {
        vector<int> nums {0};
        assert(solution.canJump(nums) == true);
    }
    {
        vector<int> nums {2,3,1,1,4};
        assert(solution.canJump(nums) == true);
    }
    {
        vector<int> nums {3,2,1,0,4};
        assert(solution.canJump(nums) == false);
    }
    {
        vector<int> nums {3,2,2,0,4};
        assert(solution.canJump(nums) == true);
    }
    {
        vector<int> nums {2,0,2,0,4};
        assert(solution.canJump(nums) == true);
    }

}
}

