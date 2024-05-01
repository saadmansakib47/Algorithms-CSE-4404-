#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100005];
ll dp[100005];

ll cutRod(ll arr[], ll isize, ll n)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    ll maxi = LONG_LONG_MIN;
    for (ll i = 1; i <= isize; i++)
    {
        ll firstCutPrice = arr[i];

        if (n - i >= 0)
        {
            ll secondCutPrice = cutRod(arr, isize, n - i);
            maxi = max(maxi, firstCutPrice + secondCutPrice);
        }
    }
    dp[n] = maxi;
    return maxi;
}

int main()
{
    ll n, x;
    cin >> x;
    for (ll i = 0; i <= 100005; i++)
    {
        dp[i] = -1;
    }
    n = x ;
    for (ll i = 1; i <= x; i++)
    {
        cin >> arr[i];
    }
    cout << cutRod(arr, x, n);

    return 0;
}
