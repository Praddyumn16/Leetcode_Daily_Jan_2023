class Solution {
public:
    void solve(int i , int last , vector<int>& nums , vector<int>& curr , vector<vector<int>>& ans) {
        
        if(i >= nums.size()) {
            if(curr.size() >= 2)
                ans.push_back(curr);
            return;
        }

        if(nums[i] >= last) {
            curr.push_back(nums[i]);
            solve(i + 1 , nums[i] , nums , curr , ans);
            curr.pop_back();
        }
        
        if(nums[i] != last)
            solve(i + 1 , last , nums , curr , ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0 , -101 , nums , curr , ans);
        return ans;
    }
};