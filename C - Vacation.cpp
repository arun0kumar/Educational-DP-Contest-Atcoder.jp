#include <bits/stdc++.h>
using namespace std;
// RECURSIVE SOLUTION
// int m;
// int sol(vector<vector<int> > v, int prev, int i)
// {
//     if(i == m)
//         return 0;
//     else if(prev == 0)
//         return max(v[i][1] + sol(v, 1, i+1), v[i][2] + sol(v, 2, i+1));
//     else if(prev == 1)
//         return max(v[i][0] + sol(v, 0, i+1), v[i][2] + sol(v, 2, i+1));
//     else
//         return max(v[i][0] + sol(v, 0, i+1), v[i][1] + sol(v, 1, i+1)); 
// }
int main() {
    int n;
    cin >> n;
    m = n;
    vector<vector<int> > v(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
//RECURSIVE SOLUTION CALL
    // int x = v[0][0] + sol(v, 0, 1);
    // int y = v[0][1] + sol(v, 1, 1);
    // int z = v[0][2] + sol(v, 2, 1);
    // // cout << x<< " " << y << " " << z;
    // cout << max(x, max(y, z));

  
 // DP SOLUTION
    int dp[n][3];
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = v[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = v[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = v[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}
