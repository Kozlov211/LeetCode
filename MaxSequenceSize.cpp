namespace Max_Sequence_Size {

class Solution {
public:
    int MaxSize(const vector<int>& seq) {
        if (seq.empty()) {
            return 0;
        }
        int max_count = 0;
        int current_count = 0;
        unordered_set<int> sub_seq;
        for (const auto value : seq) {
            if (sub_seq.count(value)) {
                if (current_count > max_count) {
                    max_count = current_count;
                }
                current_count = 0;
                sub_seq.clear();
            }
            sub_seq.insert(value);
            ++current_count;
        }
        if (current_count > max_count) {
            max_count = current_count;
        }
        return max_count;
    }
};

void Tests() {
    Solution solution;
    {
        std::vector<int> seq{1, 2, 3};
        assert(solution.MaxSize(seq) == 3);
    }
    {
        std::vector<int> seq{1, 2, 2, 3};
        assert(solution.MaxSize(seq) == 2);
    }
    {
        std::vector<int> seq{1, 1, 2, 3};
        assert(solution.MaxSize(seq) == 3);
    }
    {
        std::vector<int> seq{1, 2, 3, 3};
        assert(solution.MaxSize(seq) == 3);
    }
    {
        std::vector<int> seq{1, 2, 4, 5, 2, 2, 6, 7, 1};
        assert(solution.MaxSize(seq) == 4);
    }
    {
        std::vector<int> seq{1, 2, 3, 4, 5, 5, 1};
        assert(solution.MaxSize(seq) == 5);
    }
}

}
