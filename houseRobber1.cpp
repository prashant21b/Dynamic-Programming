#include <bits/stdc++.h>

using namespace std;
class House
{
public:
    // memoization
   /* int solve(int n, vector<int> &nums, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        // rob
        if (dp[n] != -1)
            return dp[n];
        int rob = nums[n] + solve(n - 2, nums, dp);
        // not rob;
        int notRob = solve(n - 1, nums, dp);
        return dp[n] = max(rob, notRob);
    }
    */
   //tabulation
   int solve(int n, vector<int> &nums, vector<int> &dp)
    {
        dp[0]=nums[0];
        
        for(int i=1;i<=n;i++){
            int rob;
            if(i-2>=0){
             rob = nums[i] +dp[i-2];
            }
            else{
                rob=nums[i];
            }
         
        // not rob;
        int notRob =dp[i-1];
        dp[i]=max(rob,notRob);
        }
        return dp[n];
    }
    int money(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    House h;
    cout << h.money(nums) << endl;
    return 0;
}