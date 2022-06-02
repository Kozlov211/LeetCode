#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            result.push_back(accumulate(nums.begin(), it + 1, 0));
        }
        return result;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {1, 1, 1, 1};
	vector<int> result = sol.runningSum(nums);
	for (auto num : result) {
		cout << num << endl;
	}
	return 0;
}
