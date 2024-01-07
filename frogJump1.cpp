#include <bits/stdc++.h>

using namespace std;
class frog
{
public:
//memoization
 /*   int solve(vector<int> &height, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int oneJump = solve(height, n - 1, dp) + abs(height[n - 1] - height[n]);
    int twoJump = solve(height, n - 2, dp) + abs(height[n - 2] - height[n]);

    dp[n] = min(oneJump, twoJump);
    return dp[n];
}
*/
//tabulation 
/*   int solve(vector<int> &height, int n, vector<int> &dp)
{
    
    dp[0]=0;
    dp[1]=abs(height[1]-height[0]);

    for(int i=2;i<=n;i++) {
     int oneJump=dp[i-1]+abs(height[i]-height[i-1]);
     int twoJump=dp[n-2]+abs(height[i-2]-height[i]);
     dp[i]=min(oneJump,twoJump);
    }
    return dp[n];
}
*/
//space optimization
int solve(vector<int> &height){
    int prev2=0;
    int prev1=abs(height[1]-height[0]);
    for(int i=2;i<height.size();i++){
        int oneJump=prev1+abs(height[i]-height[i-1]);
        int twoJump=prev2+abs(height[i-2]-height[i]);
       int ans=min(oneJump,twoJump);
       prev2=prev1;
       prev1=ans;

    }
    return prev1;
}

    int frogJump(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n,-1);
        return solve(height);
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
        frog fg;
        cout << fg.frogJump(height) << endl;
    }

    return 0;
}