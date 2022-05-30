#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
		if (strs.empty()) {
			return result;
		}
		sort(strs.begin(), strs.end());
		string a = strs[0];
		string b = strs[strs.size() - 1];
		for (size_t i = 0; i < a.size(); ++i) {
			if (a[i] == b[i]) {
				result += a[i];
			} else {
				return result;
			} 
		}	
		return result;		
	}
};

int main() {
	Solution sol;
	vector<string> input = {"flower","flow","flight"};
	cout << sol.longestCommonPrefix(input) << endl;
	return 0;
}
