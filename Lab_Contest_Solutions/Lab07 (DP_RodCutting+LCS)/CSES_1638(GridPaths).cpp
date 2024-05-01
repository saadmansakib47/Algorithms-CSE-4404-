#include <bits/stdc++.h>
using namespace std;

const int md = 1000000007;
int dp[1005][1005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == '*')
                dp[i][j] = 0;
            else if (i * j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % md;
        }
    }
    cout << dp[n][n];
}

int main()
{
    solve();
    return 0;
}
