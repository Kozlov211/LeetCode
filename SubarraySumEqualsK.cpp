namespace Subarray_Sum_Equals_K {

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        vector<int> prefix_sum(nums.size());
        prefix_sum[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        unordered_map<int, int> map_;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (prefix_sum[i] == k) {
                ++result;
            }
            if (map_.count(prefix_sum[i] - k)) {
                result += map_[prefix_sum[i] - k];
            }
            map_[prefix_sum[i]]++;
        }
        return result;
    }
};

void Tests() {
     Solution solution;
     {
         vector<int> nums {1,1,1};
         assert(solution.subarraySum(nums, 2) == 2);
     }
     {
         vector<int> nums {1,2,3};
         assert(solution.subarraySum(nums, 3) == 2);
     }
     {
         vector<int> nums {1};
         assert(solution.subarraySum(nums, 1) == 1);
     }
     {
         vector<int> nums {2,1,2};
         assert(solution.subarraySum(nums, 2) == 2);
     }

}

}

