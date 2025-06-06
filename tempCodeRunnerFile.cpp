#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MOD = 1000000007;

vector<vector<int>> dp;
vector<int> coins;
int n;

int solve(int sum, int idx)
{
    if (sum == 0)
        return 1;
    if (idx >= n || sum < 0)
        return 0;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int result = 0;

    result = solve(sum, idx + 1);

    if (sum >= coins[idx])
    {
        result = (result + solve(sum - coins[idx], idx)) % MOD;
    }

    return dp[idx][sum] = result;
}

void sol()
{
    cin >> n;
    int x;
    cin >> x;

    coins.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    dp.assign(n + 1, vector<int>(x + 1, -1));

    cout << solve(x, 0) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        sol();
    }
}