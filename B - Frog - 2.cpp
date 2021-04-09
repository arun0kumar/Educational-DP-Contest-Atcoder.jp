#include <bits/stdc++.h>
using namespace std;

// int solve(int cost[], int n, int k)
// {
//     if(n <= 1)
//         return 0;
//     else{
//         int ans = INT_MAX;
//         for(int i = 1; i <= k; i++)
//         {
//             ans = min(ans, abs(cost[n-1] - cost[n-i-1]) + solve(cost, n-i, k));
//         }
//         return ans;
//     }
// }
int solve(int cost[], int n, int k)
{
    int dp[n+1] = {0};
    for(int i = 2; i <= n; i++)
    {
        int ans = INT_MAX;
        for(int j = 1; j <= k; j++)
        {
            if(i-j >= 1)
                ans = min(ans, abs(cost[i-1] - cost[i-j-1]) + dp[i-j]);
        }
        // if(i > k){
        //     for(int j = 1; j <= k; j++)
        //     {
        //         ans = min(ans, abs(cost[i-1] - cost[i-j-1]) + dp[i-j]);
        //     }
        // }
        // else{
        //     for(int j = 1; j <= min(i, k); j++)
        //     {
        //         ans = min(ans, abs(cost[i-1] - cost[i-j-1]) + dp[i-j]);
        //     }
        // }

        dp[i] = ans;
    }
    return dp[n];

}
int main() {
    int n, k;
    cin >> n >> k;
    int cost[n];
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    cout << solve(cost, n, k);
}
