#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int long long
#define pii pair<int, int>
#define pb push_back
#define gcd __gcd
#define lcm(a, b) (a * b) / gcd(a, b)
#define all(a) a.begin(), a.end()
#define mem(a, x) memset(a, x, sizeof(a))
#define f(i, s, e) for (int i = s; i <= e; i++)
#define ff(i, s, e) for (int i = s; i >= e; i--)
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define maxn (ll)(2e5 + 5000)
#define INF LONG_LONG_MAX
using namespace std;
// set<int>::iterator it;

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int ans = 0;
    int n, d;
    cin >> n >> d;
    vector<vector<int>> g(n + 5);
    f(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        //树形图
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> vis(n + 5, 0);
    function<void(int, int)> dfs = [&](int u, int dis) {
        if (vis[u])
        {
            return;
        }
        vis[u] = 1;
        if (dis == d)
        {
            return;
        }
        for (auto v : g[u])
        {
            if(!vis[v])//如果v已经访问过了，就不再访问
            {
                dfs(v, dis + 1);
                ans++;
            }
        }
    };
    dfs(1, 0);
    cout << ans << endl;

    return 0;
}