class Solution {
public:
    int dfs(int curr , int prev , vector<vector<int>>& adj , vector<bool>& hasApple) {
        
        int temp = 0;

        for(auto a : adj[curr]) {
            if(a != prev) {
                temp += dfs(a , curr , adj , hasApple);
            }
        }

        if(temp == 0 && !hasApple[curr])
            return 0;
        
        return (curr == 0 ? temp : temp + 2);
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(auto a : edges) {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }

        return dfs(0 , -1 , adj , hasApple);
    }
};