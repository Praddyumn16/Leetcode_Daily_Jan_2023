class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> tokens;
        for (auto i = strtok(&s[0], " "); i != NULL; i = strtok(NULL, " "))
            tokens.push_back(i);
        
        vector<int> v1;
        unordered_map<string , int> mp;
        int curr = 0;

        for(auto a : tokens) {
            if(mp.count(a))
                v1.push_back(mp[a]);
            else {
                v1.push_back(curr);
                mp[a] = curr++;
            }
        }

        vector<int> v2;
        unordered_map<char , int> mp1;
        curr = 0;

        for(auto a : pattern) {
            if(mp1.count(a))
                v2.push_back(mp1[a]);
            else {
                v2.push_back(curr);
                mp1[a] = curr++;
            }
        }
        
        return v1 == v2;
    }
};