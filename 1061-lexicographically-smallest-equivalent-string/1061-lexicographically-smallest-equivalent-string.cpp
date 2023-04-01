class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int val[26];
        for(int i = 0 ; i < 26 ; i++)
            val[i] = i;
        
        int n = s1.size();

        for(int i = 0 ; i < n ; i++) {
            
            int mini = min(val[s1[i] - 'a'] , val[s2[i] - 'a']);
            int maxi = max(val[s1[i] - 'a'] , val[s2[i] - 'a']);

            for(int i = 0 ; i < 26 ; i++)
                if(val[i] == maxi)
                    val[i] = mini;
        }

        string ans = "";
        for(auto a : baseStr) 
            ans += (val[a - 'a'] + 'a');
        
        return ans;
    }
};