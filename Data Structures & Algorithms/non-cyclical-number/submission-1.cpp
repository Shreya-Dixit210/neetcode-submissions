class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;

        while (n != 1) {
            if (m.find(n) != m.end()) {
                return false;
            }

            m[n] = 1;

            int sum = 0;

            while (n > 0) {
                int last = n % 10;
                sum += last * last;
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};
