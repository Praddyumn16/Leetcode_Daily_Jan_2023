class Solution {
public:
    bool valid(string s) {
        if(!s.size() || s.size() > 3) return false;
        if(s.size() > 1 && s[0] == '0') return false;
        if(s.size() && stoi(s) > 255) return false;
        return true;
    }

    void solve(int i , int dots , string curr , string& s , vector<string>& ans) {
        if(dots == 3) {
            if(valid(s.substr(i))) {
                curr += s.substr(i);
                ans.push_back(curr);
            }
            return;
        }
        
        int n = s.size();

        for(int idx = i ; idx < min(i + 3 ,n) ; idx++) {
            if(valid(s.substr(i , idx - i + 1))) {
                curr += s[idx];
                curr += ".";
                solve(idx + 1 , dots + 1 , curr , s , ans);
                curr.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(0 , 0 , "" , s , ans);
        return ans;    
    }
};