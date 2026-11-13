class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char c : tasks) freq[c - 'A']++;

        int maxFreq = *max_element(freq, freq + 26);
        int maxCount = 0;
        for (int i = 0; i < 26; i++)
            if (freq[i] == maxFreq) maxCount++;

        int slots = (maxFreq - 1) * (n + 1) + maxCount;
        return max((int)tasks.size(), slots);
    
    }
};
