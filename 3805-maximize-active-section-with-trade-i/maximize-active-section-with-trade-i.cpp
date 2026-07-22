class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s= "1"+s+"1";
        int zero =0;
        int one =0;
        vector<int> ans;
        for(int i =0;i<s.size();i++){
            if(s[i]=='0'){
                 zero++;
            }else{
                if(i!=0 && i!=s.size()-1){
                    one++;
                }
                if(zero>0){
                        ans.push_back(zero);
                        zero=0;
                }
            }
        }
        
        int maxi =0;
        if(ans.size()<2){
            return one ;
        }

        for(int i =1;i<ans.size();i++){
            maxi = max(maxi, ans[i]+ans[i-1]);
        }

        return one+maxi;
    }
};