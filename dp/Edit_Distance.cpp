// AG___
// There is a one percent chance, and sometimes that chance is good enough.
// But what matters is what you think about that one percent.

// Template Credits- Punpun018
/****************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
vector<vector<int>> dp;
int calc(int i, int j, string &s1, string &s2)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = calc(i - 1, j - 1, s1, s2);
    int insert = calc(i, j - 1, s1, s2);
    int remove = calc(i - 1, j, s1, s2);
    int replace = calc(i - 1, j - 1, s1, s2);
    return dp[i][j] = 1 + min({insert, remove, replace});
}
void sol()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    dp.assign(n + 1, vector<int>(m + 1, -1));
    cout << calc(n, m, s1, s2) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        sol();
    }
}