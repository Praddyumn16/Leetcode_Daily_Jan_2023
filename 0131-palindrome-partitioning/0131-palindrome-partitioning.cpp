class Solution {
public:

vector<vector<string>> ans;

    bool check(string s) {
        string temp = s;
        reverse(temp.begin() , temp.end());
        return temp == s;
    }

    void solve(int i , string curr , string &s , vector<string> &v) {
        if(i == s.size()) {
            ans.push_back(v);
            return;
        }

        for(int j = i ; j < s.size() ; j++) {
            curr += s[j];
            if(check(curr)){
                v.push_back(curr);
                solve(j + 1 , "" , s , v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(0 , "" , s , v);
        return ans;
    }
};