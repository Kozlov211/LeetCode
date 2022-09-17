namespace Is_Subsequence {

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty() && t.empty()) {
            return true;
        }
        for (size_t i = 0; i < t.size(); ++i) {
            if (s[0] == t[i]) {
                s = s.substr(1);
            }
            if (s.empty()) {
                return true;
            }
        }
        return false;
    }
};

void Tests() {
    Solution solution;
    {
        string s = "abc";
        string t = "ahbgdc";
        assert(solution.isSubsequence(s, t) == true);
    }
    {
        string s = "axc";
        string t = "ahbgdc";
        assert(solution.isSubsequence(s, t) == false);
    }
    {
        string s = "axc";
        string t = "abcxd";
        assert(solution.isSubsequence(s, t) == false);
    }
    {
        string s = "";
        string t = "abcxd";
        assert(solution.isSubsequence(s, t) == true);
    }

}

}
