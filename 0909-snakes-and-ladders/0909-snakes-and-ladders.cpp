class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        
        vector<pair<int, int>> cells(n * n + 1);
        vector<int> columns(n);
        
        for(int i = 0 ; i < n ; i++)
            columns[i] = i;
        
        int cell = 1;
        
        for(int row = n - 1 ; row >= 0 ; row--) {
            for(auto a : columns) 
                cells[cell++] = {row , a};
            reverse(columns.begin() , columns.end());
        }

        vector<int> dist(n * n + 1 , -1);
        dist[1] = 0;
        
        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(int next = curr + 1 ; next <= min(curr + 6 , n * n) ; next++) {
                int row = cells[next].first , col = cells[next].second;
                int destination = (board[row][col] == -1 ? next : board[row][col]);
                if(dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }

        return dist[n * n];
    }
};