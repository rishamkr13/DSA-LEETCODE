class Solution {
public: 
int t[201][201][201];
int mod = 1e9+7;
    int solve(vector<int>& nums, int i,int gcd1,int gcd2){
        
        if(i==nums.size()){
            bool emp = (gcd1!=0 && gcd2!=0);
            bool gcdm = (gcd1==gcd2);
            return (emp && gcdm) ? 1: 0;
        }
        if(t[i][gcd1][gcd2]!=-1){
            return t[i][gcd1][gcd2];
        }
         int seq1 = solve(nums, i+1,__gcd(gcd1,nums[i]),gcd2);
        int  seq2 = solve(nums, i+1,gcd1,__gcd(gcd2,nums[i]));
        int skip = solve(nums, i+1, gcd1,gcd2);
        return t[i][gcd1][gcd2]=  (0LL +seq1 + seq2 + skip) % mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,0);
    }
};