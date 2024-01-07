#include <bits/stdc++.h>

using namespace std;
class frog
{
public:
    // memoization

    // int solve(int n, int k, vector<int> &height, vector<int> &dp)
    // {
    //     if (n == 0)
    //     {
    //         return 0;
    //     }
    //     if (dp[n] != -1)
    //         return dp[n];
    //     int mini = INT_MAX;
    //     for (int i = 1; i <= k; i++)
    //     {
    //         int jump = INT_MAX;
    //         if (n - i >= 0)
    //             jump = solve(n - i, k, height, dp) + abs(height[n] - height[n - i]);
    //         mini = min(mini, jump);
    //     }
    //     dp[n] = mini;
    //     return dp[n];
    // }
// tabulation
int solve(int n, int k, vector<int> &height,vector<int> &dp){
   dp[0]=0;
   dp[1]=abs(height[1]-height[0]);
   
   for(int j=2;j<=n;j++){
        int mini=INT_MAX;
    for(int i=1;i<=k;i++){
        int jump=INT_MAX;
        if(j-i >=0) jump=dp[j-i]+abs(height[j]-height[j-i]);
             mini=min(mini,jump);
        
        
    }
    dp[j]=mini;
   }
     return dp[n];

}
    int frogJump(vector<int> &height, int k)
    {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return solve(n - 1, k, height, dp);
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> height(n);
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        int k;
        cin >> k;
        frog fg;
        cout << fg.frogJump(height, k) << endl;
    }

    return 0;
}