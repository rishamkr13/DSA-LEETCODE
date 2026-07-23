class Solution {
public:
    bool isPal(string s,int i, int j){
       
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
        j--;
        }
        return true;
        
        
    }
    void solve(string s , int idx, vector<string>& store, vector<vector<string>>& ans){
        if(idx==s.size()){
            ans.push_back(store);
            return;
        }
        for(int i=idx; i<s.size();i++){
            if(isPal(s,idx,i)){
                store.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,store, ans);
                store.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> store;
        solve(s,0,store,ans);
        return ans;
    }
};