namespace Reverse_String {

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        for (size_t i = 0; i < s.size() / 2; ++i) {
            std::swap(s[i], s[s.size() - 1 - i]);
        }
    }
};

void Tests() {
    Solution solution;
    {
        vector<char> s;
        solution.reverseString(s);
        vector<char> result;
        assert(s == result);
    }
    {
        vector<char> s = {'h','e','l','l','o'};
        solution.reverseString(s);
        vector<char> result = {'o', 'l', 'l', 'e', 'h'};
        assert(s == result);
    }
    {
        vector<char> s = {'H','a','n','n','a','h'};
        solution.reverseString(s);
        vector<char> result = {'h','a','n','n','a','H'};
        assert(s == result);
    }
    {
        vector<char> s = {'H'};
        solution.reverseString(s);
        vector<char> result = {'H'};
        assert(s == result);
    }
}
