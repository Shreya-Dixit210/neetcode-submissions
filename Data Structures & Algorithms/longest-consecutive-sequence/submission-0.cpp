class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int count = 1;
        int maxCount = 1;
        for(int i  = 0; i< nums.size(); i++){
            s.insert(nums[i]);
        }
        if(s.empty()){
            return 0;
        }
        auto it = s.begin();
        int prev = *it;
        for(++it; it != s.end(); ++it){
            int x = *it;
            if(x == prev + 1){
                count++;
            }else
                count = 1;
            prev = x;
            maxCount = max(maxCount , count);
        }
        return maxCount;
    }
};
