namespace Path_Crossing {

class Solution {
public:
    bool isPathCrossing(string path) {
        using point = std::pair<uint32_t, uint32_t>;
        set<point> points;
        point current_point = {0, 0};
        points.insert(current_point);
        for (auto& element : path) {
            if (element == 'N') {
                current_point.second += 1;
            } else if (element == 'S') {
                current_point.second -= 1;
            } else if (element == 'E') {
                current_point.first += 1;
            } else {
                current_point.first -= 1;
            }
            if (points.count(current_point)) {
                return true;
            } else {
                points.insert(current_point);
            }
        }
        return false;
    }
};

void Tests() {
    Solution solution;
    {
        string path = "NES";
        assert(solution.isPathCrossing(path) == false);
        path = "N";
        assert(solution.isPathCrossing(path) == false);
        path = "NESWW";
        assert(solution.isPathCrossing(path) == true);
    }
}

}
