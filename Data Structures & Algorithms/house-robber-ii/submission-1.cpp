class Solution {
private:
    int f(vector<int>& dp,int p,int e,vector<int>& nums)
    {
        if(p<e) return 0;
        if(dp[p]!=-1) return dp[p];

        int take=nums[p]+f(dp,p-2,e,nums);
        int nottake=f(dp,p-1,e,nums);
        return dp[p]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int t1=f(dp1,n-1,1,nums);
        int t2=f(dp2,n-2,0,nums);
        return max(t2,t1);
    }
};
