namespace Replace_Elements_with_Greatest_Element_on_Right_Side {

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result (arr.size());
        result[result.size() - 1] = -1;
        for (size_t i = arr.size() - 1; i > 0; --i) {
            result[i - 1] = max(result[i], arr[i]);
        }
        return result;
    }
};

void Tests() {
    Solution solution;
    {
        vector<int> test {17,18,5,4,6,1};
        vector<int> answer {18,6,6,6,1,-1};
        assert(solution.replaceElements(test) == answer);
    }
    {
        vector<int> test {40};
        vector<int> answer {-1};
        assert(solution.replaceElements(test) == answer);
    }
}

}

