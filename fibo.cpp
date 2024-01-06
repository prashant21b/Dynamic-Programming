#include<bits/stdc++.h>

using namespace std;
class fibo{
    public:
    //using recursion
    /*int solve(int n){
        if(n<=1){
            return n;
        }
        return solve(n-1)+solve(n-2);
    }
    */
   //using memo
  /* int solve(int n,vector<int> &dp){
     if(n<=1) {
        return n;
     }
     if(dp[n]!=-1){
        return dp[n];
     }
     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
   }
   */
  //using tabulation(bottom up approch)
   /* int solve(int n,vector<int> &dp){
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    */
   //space optimization
   int solve(int n){
     int prev2=0;
     int prev1=1;
     for(int i=2;i<=n;i++){
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
     }
     return prev1;
   }
     int nthfibo(int n){
        vector<int> dp(n+1,-1);
       return solve(n);
     }

};
int main(){
int n;
cin>>n;
fibo fb;
int ans=fb.nthfibo(n);
cout<<"Nth fibo-> "<<ans<<endl;

    return 0;
}