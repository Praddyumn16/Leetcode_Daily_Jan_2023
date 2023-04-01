class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int n = s.size();

        vector<int> left_ones(n , 0);
        vector<int> right_zeroes(n , 0);
        
        for(int i = 0 ; i < n - 1 ; i++) {
            if(s[i] == '1')
                left_ones[i + 1] = 1 + left_ones[i];
            else
                left_ones[i + 1] = left_ones[i];
        }

        for(int i = n - 1 ; i > 0 ; i--) {
            if(s[i] == '0')
                right_zeroes[i - 1] = 1 + right_zeroes[i];
            else
                right_zeroes[i - 1] = right_zeroes[i];
        }

        int ans = INT_MAX;
    
        for(int i = 0 ; i < n ; i++)
            ans = min(ans , left_ones[i] + right_zeroes[i]);

        return ans;
    }
};