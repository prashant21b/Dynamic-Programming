#include <bits/stdc++.h>
using namespace std;
class climbingStair
{

public:
    // recursive approch
    //  int solve(int n){
    //      //base case
    //      if(n<=0){
    //          return 1;
    //      }
    //      //base case
    //      if(n==1){
    //          return 1;
    //      }
    //      return solve(n-1)+solve(n-2);
    //  }

    // top down
    // int solve(int n, vector<int> &dp)
    // {
    //     if (n <= 0)
    //     {
    //         return 1;
    //     }
    //     if (n == 1)
    //     {
    //         return 1;
    //     }
    //     if (dp[n] != -1)
    //         return dp[n];
    //     return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    // }
//bottom up approch
// int solve(int n,vector<int> &dp){
//     dp[0]=1;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }

//space optimization

int solve(int n){
int prev2=1;
int prev1=1;
for(int i=2;i<=n;i++){
    int curr=prev2+prev1;
    prev2=prev1;
    prev1=curr;

}
return prev1;
}
    int climb(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n);
    }
};
int main()
{
    int n;
    cin >> n;
    climbingStair cs;
    int res = cs.climb(n);
    cout << "ANS-> " << res << endl;

    return 0;
}