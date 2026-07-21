class Solution {
public:
    void generate(int i ,vector<int>& nums, int end,long long  sum , vector<long long>& res){
        if(i ==end){
            res.push_back(sum);
            return ;
        }

        generate(i+1, nums, end, sum+nums[i],res);
        generate(i+1,nums,end,sum, res);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<long long> left, right;
    long long ans =LLONG_MAX;
        generate(0,nums,n/2,0 ,left);
        generate(n/2,nums,n,0,right);
        sort(right.begin(),right.end());
        for(long long x : left){
            long long need = goal - x;
            auto it = lower_bound(right.begin(),right.end(),need);
            if(it!=right.end()){
                ans= min(ans, abs(x+ *it - goal));
            }
            if(it!=right.begin()){
                --it;
                ans= min(ans, abs(x+ *it-goal));
            }
        }
        return (int)ans;
    }
};