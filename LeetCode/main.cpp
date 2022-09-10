#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>

using namespace std;


///Solution26. Remove Duplicates from Sorted Array
class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 1;
        int tmp = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != tmp) {
                tmp = nums[i];
                nums[result++] = tmp;

            }
        }
        return result;
    }
};

///Solution80. Remove Duplicates from Sorted Array II
class Solution80 {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 2;
        for (size_t i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[index - 1] || nums[i] != nums[index - 2]) {
                nums[index++] = nums[i];
            }
        }
        return nums.size() == 1 ? 1 : index;
    }
};

///4. Median of Two Sorted Arrays
class Solution4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result (nums1.size() + nums2.size());
        size_t point1 = 0;
        size_t point2 = 0;
        size_t point = 0;
        while (point1 != nums1.size() && point2 != nums2.size()) {
            if (nums1[point1] > nums2[point2]) {
                result[point++] = nums2[point2++];
            } else {
                result[point++] = nums1[point1++];
            }
        }
        while (point1 != nums1.size()) {
            result[point++] = nums1[point1++];
        }
        while (point2 != nums2.size()) {
            result[point++] = nums2[point2++];
        }
        return result.size() % 2 == 0 ? (result[point / 2] + result[(point - 1) / 2]) / 2. : result[point / 2];
    }
};


///11. Container With Most Water
class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int range_begin = 0;
        int range_end = height.size() - 1;
        int ans = 0;
        int tmp = 0;
        while (range_begin < range_end) {
           if (height[range_begin] <= height[range_end]) {
               tmp = height[range_begin] * (range_end - range_begin);
               ++range_begin;
           } else {
               tmp = height[range_end] * (range_end - range_begin);
               --range_end;
           }
           ans = tmp > ans ? tmp : ans;
        }
        return ans;
    }
};

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


namespace Largest_Number_After_Digit_Swaps_by_Parity {

class Solution {
public:
    int largestInteger(int num) {
        string num_as_string = to_string(num);
        string odd, even;
        for (auto num : num_as_string) {
            if ((int)(num) % 2 == 0) {
                even += num;
            } else {
                odd += num;
            }
        }
        sort(odd.begin(), odd.end(), [](auto lhs, auto rhs) {
            return lhs > rhs;
        });
        sort(even.begin(), even.end(), [](auto lhs, auto rhs) {
            return lhs > rhs;
        });
        for (size_t i = 0, even_i = 0, odd_i = 0; i < num_as_string.size(); ++i) {
            num_as_string[i] = (int)(num_as_string[i]) % 2 == 0 ? even[even_i++] : odd[odd_i++];
        }
        return stoi(num_as_string);
    }
};


void Tests() {
    Solution solution;
    {
        int num = 1234;
        assert(solution.largestInteger(num) == 3412);
    }
    {
        int num = 1;
        assert(solution.largestInteger(num) == 1);
    }
    {
        int num = 65875;
        assert(solution.largestInteger(num) == 87655);
    }
    {
        int num = 23;
        assert(solution.largestInteger(num) == 23);
    }
    {
        int num = 247;
        assert(solution.largestInteger(num) == 427);
    }
}

}

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

namespace Climbing_Stairs {

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> count (n + 1);
        count[0] = 1;
        count[1] = 1;
        for (size_t i = 2; i < count.size(); ++i) {
            count[i] = count[i - 1] +  count[i - 2];
        }
        return count[n];
    }
};

void Tests() {
    Solution solution;
    assert(solution.climbStairs(1) == 1);
    assert(solution.climbStairs(2) == 2);
    assert(solution.climbStairs(3) == 3);
    assert(solution.climbStairs(4) == 5);
    assert(solution.climbStairs(5) == 8);

}

}

namespace Ugly_Number_II {

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        vector<int> result(n);
        result[0] = 1;
        result[1] = 2;
        result[2] = 3;
        for (int i = 3; i < n; ++i) {
            result[i] = min(result[i - 3] * 5, min(result[i - 2] * 3, result[i - 1] * 2));
        }
        return result[n - 1];
    }
};

void Tests() {
    Solution solution;
    assert(solution.nthUglyNumber(1) == 1);
    assert(solution.nthUglyNumber(10) == 12);
}

}


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


}




int main()
{
    Pascal_Triangle::Tests();
    return 0;
}
