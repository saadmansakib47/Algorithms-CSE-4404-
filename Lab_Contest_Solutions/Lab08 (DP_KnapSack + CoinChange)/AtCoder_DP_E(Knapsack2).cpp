#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<long long> w(N);
    vector<long long> v(N);
    for(int i = 0; i < N; i++)
    {
        cin >> w.at(i) >> v.at(i);
    }
    vector<vector<long long>> dp(N + 1, vector<long long>(pow(10, 5) + 1, pow(10, 9) + 1));
    dp.at(0).at(0) = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= pow(10, 5); j++)
        {
            if(j - v.at(i) >= 0)
            {
                dp.at(i+1).at(j) = min(dp.at(i).at(j - v.at(i)) + w.at(i), dp.at(i).at(j));
            }
            else
            {
                dp.at(i+1).at(j) = dp.at(i).at(j);
            }
        }
    }
    for(int i = pow(10,5); i >= 0; i--)
    {
        if(dp.at(N).at(i) <= W)
        {
            cout << i << endl;
            return 0;
        }
    }
}
