#include <bits/stdc++.h>
using namespace std;

int ans(int n, vector<int> &dp, int a, int b, int c) {
    if (n == 0) return 0; 
    if (n < 0) return -1e5; 
    if (dp[n] != -1) return dp[n];

   
    return dp[n] = max({1 + ans(n - a, dp, a, b, c), 
                        1 + ans(n - b, dp, a, b, c), 
                        1 + ans(n - c, dp, a, b, c)});
}

void sol() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n + 1, -1);
    int result = ans(n, dp, a, b, c);

    if (result < 0) 
        cout << "-1" << endl;
    else
        cout << result << endl;
}

int main() {
    sol();
    return 0;
}
