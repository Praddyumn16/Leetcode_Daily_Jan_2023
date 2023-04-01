class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int , int> mp;

        for(auto a : tasks)
            mp[a]++;
        
        int ans = 0;
        
        for(auto a : mp) {
            int count = a.second;
            if(count < 2)
                return -1;
            while(count) {
                if(count == 3 || count == 2)
                    count = 0;
                else if(count >= 5)
                    count -= 3;
                else 
                    count -= 2;
                ans++;
            }
        }

        return ans;
    }
};