namespace Sort_Array_By_Parity {

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        vector<int> odd;
        for (auto num : nums) {
            if (num % 2 == 0) {
                result.push_back(num);
            } else {
                odd.push_back(num);
            }
        }
        for (auto num : odd) {
            result.push_back(num);
        }
        return result;
    }
};

void Tests() {
    Solution solution;
    {
        vector<int> nums {3,1,2,4};
        vector<int> ans {2,4,3,1};
        assert(solution.sortArrayByParity(nums) == ans);
    }
    {
        vector<int> nums {0};
        vector<int> ans {0};
        assert(solution.sortArrayByParity(nums) == ans);
    }
    {
        vector<int> nums {1,1,1,1,1};
        vector<int> ans {1,1,1,1,1};
        assert(solution.sortArrayByParity(nums) == ans);
    }
    {
        vector<int> nums {4222,3790,2103,1294,2556,2025,3919,1516,2383,2917};
        vector<int> ans {4222,3790,1294,2556,1516,2103,2025,3919,2383,2917};
        assert(solution.sortArrayByParity(nums) == ans);
    }
}

}
