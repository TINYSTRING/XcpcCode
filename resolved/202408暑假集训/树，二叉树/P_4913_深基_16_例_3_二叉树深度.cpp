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
    int n;
    cin >> n;
    // vector<int> tree(n+1);
    vector<vector<int>> g(n + 1);
    f(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        if (!u && !v)
        {
            continue;
        }
        g[i].pb(u);
        g[i].pb(v);
    }
    // 计算树的最大深度
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int d) {
        ans = max(ans, d);
        for (auto v : g[u])
        {
            dfs(v, d + 1);
        }
    };
    dfs(1, 1);
    cout << ans << endl;

    return 0;
}