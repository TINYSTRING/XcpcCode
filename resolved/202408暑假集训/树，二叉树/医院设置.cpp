// 解法二：树的重心 O(n)
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
    vector<vector<int>> g(n + 1);
    vector<int> w(n + 1, 0);
    f(i, 1, n)
    {
        int u, v;
        cin >> w[i];
        cin >> u >> v;
        if (u)
        {
            g[i].pb(u);
            g[u].pb(i);
        }
        if (v)
        {
            g[i].pb(v);
            g[v].pb(i);
        }
    }
    // 求树的重心
    vector<int> sz(n + 1, 0); // 子树大小
    vector<int> F(n + 1, 0);  // 以i为根的子树的F值
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) -> void {
        sz[u] = w[u]; // 初始化子树大小
        for (auto v : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            dfs(v, u, d + 1);
            sz[u] += sz[v];
        }
        F[1] += w[u] * d;
    };
    int ans = 4e18;
    function<void(int, int)> dfs2 = [&](int u, int fa) -> void {
        for (auto v : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            F[v] = F[u] + sz[1] - 2 * sz[v];// 以v为根的子树的F值
            dfs2(v, u);
        }
        ans = min(ans, F[u]);
    };
    dfs(1, 0, 0);
    dfs2(1, 0);
    cout << ans << endl;
    return 0;
}
// 解法一：遍历每个节点，以每个节点为根节点，计算每个节点到其他节点的距离和，取最小值 O(n^2)
//  #include <bits/stdc++.h>
//  #define endl '\n'
//  #define ll long long
//  #define int long long
//  #define pii pair<int, int>
//  #define pb push_back
//  #define gcd __gcd
//  #define lcm(a, b) (a * b) / gcd(a, b)
//  #define all(a) a.begin(), a.end()
//  #define mem(a, x) memset(a, x, sizeof(a))
//  #define f(i, s, e) for (int i = s; i <= e; i++)
//  #define ff(i, s, e) for (int i = s; i >= e; i--)
//  #define setbits(x) __builtin_popcount(x)
//  #define zrobits(x) __builtin_ctzll(x)
//  #define mod 1000000007
//  #define maxn (ll)(2e5 + 5000)
//  #define INF LONG_LONG_MAX
//  using namespace std;
//  // set<int>::iterator it;

// signed main(void)
// {
//     ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//     int n;
//     cin >> n;
//     vector<vector<int>> g(n + 1);
//     vector<int> w(n + 1, 0);
//     f(i, 1, n)
//     {
//         int u, v;
//         cin >> w[i];
//         cin >> u >> v;
//         if (u)
//         {
//             g[i].pb(u);
//             g[u].pb(i);
//         }
//         if (v)
//         {
//             g[i].pb(v);
//             g[v].pb(i);
//         }
//     }
//     int ans = 4e18, sum = 0;
//     function<void(int, int, int)> dfs = [&](int u, int fa, int d) -> void {
//         sum += w[u] * d;
//         for (auto v : g[u])
//         {
//             if (v == fa)
//             {
//                 continue;
//             }
//             dfs(v, u, d + 1);
//         }
//     };
//     f(i, 1, n)
//     {
//         dfs(i, 0, 0);
//         ans = min(ans, sum);
//         sum = 0;
//     }
//     cout << ans << endl;
//     return 0;
// }
