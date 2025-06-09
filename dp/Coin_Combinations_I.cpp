// AG___
// There is a one percent chance, and sometimes that chance is good enough. But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define mod 1000000007
void sol()
{
    int n, x;
    cin >> n >> x;
    // Dp top down approch
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
                dp[i] = (dp[i] + dp[i - c[j]]) % mod;
        }
    }
    cout << dp[x] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        sol();
    }
}