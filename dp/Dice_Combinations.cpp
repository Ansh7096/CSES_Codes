// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
void sol()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout << dp[n] << endl;
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