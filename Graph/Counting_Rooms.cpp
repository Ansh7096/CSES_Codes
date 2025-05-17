#include <bits/stdc++.h>
using namespace std;
void bfs(int x, int y, vector<vector<bool>> &vis, vector<vector<char>> &v, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    while (!q.empty())
    {
        int zx = q.front().first;
        int zy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = zx + dx[i];
            int ny = zy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && v[nx][ny] == '.')
            {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout<<v[i][j]<<" "<<vis[i][j]<<endl;
            if (v[i][j] == '.' && !vis[i][j])
            {
                ans++;
                bfs(i, j, vis, v, n, m);
            }
        }
    }
    cout << ans << endl;
    // for (int i = 0; i < n; i++)
}