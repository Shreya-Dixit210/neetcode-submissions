class CountSquares {

public:
    map<pair<int,int>, int> mp;

    CountSquares() {

    }

    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for (auto p : mp) {
            int x2 = p.first.first;
            int y2 = p.first.second;

            if (x == x2 || abs(x - x2) != abs(y - y2))
                continue;

            ans += p.second * mp[{x, y2}] * mp[{x2, y}];
        }

        return ans;
    }
};
