class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int maxArea = 0;
        while(i != j){
            int w = j - i;
            int ht = min(heights[i] , heights[j]);
            int currArea = ht  * w;
            maxArea = max( maxArea , currArea);
            heights[i] < heights[j] ? i++ : j--;
            
        }
        return maxArea;
    }
};
