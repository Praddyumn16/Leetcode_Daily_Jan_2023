class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        vector<int> v(n);
        
        v[0] = gas[0] - cost[0];
        int low = v[0] , lowest_idx = 0;

        for(int i = 1 ; i < n ; i++){
            v[i] = gas[i] - cost[i] + v[i - 1];
            if(v[i] < low) {
                low = v[i];
                lowest_idx = i;
            }
        }

        return (v[n - 1] >= 0 ? (lowest_idx + 1) % n : -1);
    }
};