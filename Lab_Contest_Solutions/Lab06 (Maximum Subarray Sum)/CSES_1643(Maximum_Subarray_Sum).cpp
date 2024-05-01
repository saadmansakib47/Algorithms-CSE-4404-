#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    int mx = a[0], sm = a[0];
    for(int i = 1; i < n; i++)
    {
        sm = max(sm + a[i], a[i]);
        mx = max(mx, sm);
    }
    cout << mx;
}

signed main()
{
    int t=1;
    while(t--){
        solve();
    }
}
