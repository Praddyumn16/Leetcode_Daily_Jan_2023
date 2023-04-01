class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size() , inf = 0 , ans = 0;

        if(n <= 2)
            return n;

        for(int i = 0 ; i < n ; i++) {
            
            unordered_map<double , int> mp;
            
            for(int j = 0 ; j < n ; j++) {
                
                if(i == j) continue;

                double up = points[j][1] - points[i][1];
                double down = points[j][0] - points[i][0];
                double slope;

                if(down == 0)
                    slope = INT_MAX;
                else 
                    slope = up / down;

                mp[slope]++;
                ans = max(ans , mp[slope]);
            }
        }

        return ans + 1;
    }
};