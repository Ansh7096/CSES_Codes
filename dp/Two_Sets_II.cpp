#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int check(int idx, vector<vector<int>> &dp, vector<int> &v, int s)
{
    if (s == 0)
        return 1;
    if (idx < 0 || s < 0)
        return 0;
    if (dp[idx][s] != -1)
        return dp[idx][s];
    int include = (s >= v[idx]) ? check(idx - 1, dp, v, s - v[idx]) : 0;
    int exclude = check(idx - 1, dp, v, s);

    return dp[idx][s] = (include + exclude) % MOD;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            v[i] = i + 1;
            s += v[i];
        }
        if (s & 1)
        {
            cout << "0" << endl;
            continue;
        }
        s = s / 2;
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
        cout << (check(n - 1, dp, v, s) * 1LL * ((MOD + 1) / 2)) % MOD << endl;
    }

    return 0;
}