#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;



class Solution {
public:
    int romanToInt(string s) {
		map<char, int>mp = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500},{'M',1000}};
		int n = s.length();
		int ans = mp[s[n-1]];
		for (int i = n-2;i >= 0; --i) {
			if(mp[s[i]] < mp[s[i + 1]]) {
				ans -= mp[s[i]];
			}
			else {
				ans += mp[s[i]];
			}
		}
		return ans;
	}
	
};

int main() {
	Solution solv;
	string s = "VVVV";
	cout << solv.romanToInt(s) << endl;
	return 0;
}
