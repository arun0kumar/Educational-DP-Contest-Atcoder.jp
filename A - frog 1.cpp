#include <iostream>
using namespace std;
// int solve(int cost[], int n)
// {
//     if(n <= 1)
//         return 0;
//     return min(abs(cost[n-1] - cost[n-2]) + solve(cost, n-1), abs(cost[n-1] - cost[n-3]) + solve(cost, n-2));
// }
int solve(int cost[], int n)
{
    int dp[n+1] = {0};
    for(int i = 2; i <= n; i++)
    {
        if(i == 2)
            dp[i] = abs(cost[i-1] - cost[i-2]);
        else
        {
            dp[i] = min(dp[i-1] + abs(cost[i-1] - cost[i-2]), dp[i-2] + abs(cost[i-1] - cost[i-3]));
        }
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    int cost[n];
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    cout << solve(cost, n);
}
