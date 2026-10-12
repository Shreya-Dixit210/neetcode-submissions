class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;
        for(int i =0; i<s.size(); i++){
            if(m.find(s[i]) == m.end())
                m.insert({s[i],1});
            else
                m.find(s[i])->second++;
        }
        for(int i=0; i<t.size(); i++){
            if(m.find(t[i]) != m.end())
                m.find(t[i])->second--;
            else
                return false;
        }
        for(auto it : m){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};
