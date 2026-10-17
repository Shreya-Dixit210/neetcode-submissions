class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Store elements in a min heap
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});

            // Keep only k elements in the heap
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 3: Extract the k most frequent elements
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
