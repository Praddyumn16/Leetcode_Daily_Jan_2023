class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int ans1 = INT_MIN , ans2 = INT_MAX , sum1 = 0 , sum2 = 0 , total = 0;

        for(auto a : nums) {
            sum1 += a , sum2 += a;
            ans1 = max(ans1 , sum1);
            ans2 = min(ans2 , sum2);
            if(sum1 < 0) sum1 = 0;
            if(sum2 > 0) sum2 = 0;
            total += a;
        }

        return (total == ans2 ? ans1 : max(ans1 , total - ans2));
    }
};