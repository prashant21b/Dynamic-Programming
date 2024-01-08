
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//memoization
   /*int solve1(vector<int> nums,int n,vector<int> &dp){
  if(n==0){
      return nums[0];
  }
  if(n<0){
      return 0;
  }
  if(dp[n]!=-1) return dp[n];
  //rob
  int rob=nums[n]+solve1(nums,n-2,dp);
  //notrob
  int notrob=solve1(nums,n-1,dp);
  return dp[n]=max(rob,notrob);
   }*/
   //tabulation 
   int solve1(vector<int> nums,int n,vector<int> &dp){
  if(n==1){
            return max(nums[0],nums[1]);
        }
  dp[0]=nums[0];
  for(int i=1;i<=n;i++){
    //rob
int rob;
if(i-2>=0){
rob=nums[i]+dp[i-2];
}
else{
    rob=nums[i];
}
  
  //notrob
  int notrob=dp[i-1];
   dp[i]=max(rob,notrob);
  }
  return dp[n];
   }
   
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> nums1, nums2;

        for(int i=1;i<nums.size();i++)
            nums1.push_back(nums[i]);

        for(int i=0;i<nums.size()-1;i++)
            nums2.push_back(nums[i]);

        vector<int> dp(nums1.size()+1, -1);
        vector<int> dp2(nums2.size()+1, -1);
        int ans = solve1(nums1,nums1.size()-1, dp);
        int ans2 = solve1(nums2,nums2.size()-1, dp2);

        return max(ans, ans2);
        
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    Solution s;
    cout<<s.rob(nums)<<endl;

}
