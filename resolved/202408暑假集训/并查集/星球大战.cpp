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
class DSU
{
  public:
    vector<int> f, siz;

    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<bool> check(n + 1, true);
    vector<pii> edges(m + 1);
    vector<vector<int>> mp(m << 1 | 1);
    f(i, 1, m)
    {
        cin >> edges[i].first >> edges[i].second;
        mp[edges[i].first].pb(edges[i].second);
        mp[edges[i].second].pb(edges[i].first); // 无向图
    }
    int k;
    cin >> k;
    vector<int> t(k);
    f(i, 0, k - 1)
    {
        cin >> t[i];
        check[t[i]] = false;
    }
    int cnt = n - k; // 去掉k个点后的连通块数
    f(i, 1, m)
    {
        if (check[edges[i].first] && check[edges[i].second] && !dsu.same(edges[i].first, edges[i].second))
        {
            cnt--; // 重新加入一条边,连通块数减少
            dsu.merge(edges[i].first, edges[i].second);
        }
    }
    vector<int> ans;
    ans.pb(cnt);
    ff(i, k - 1, 0)
    {
        cnt++; // 重新加入一个点
        check[t[i]] = true;
        for (auto x : mp[t[i]])
        {
            if (check[x] && !dsu.same(t[i], x))
            {
                cnt--;
                dsu.merge(t[i], x);
            }
        }
        ans.pb(cnt);
    }
    ff(i, ans.size() - 1, 0)
    {
        cout << ans[i] << endl;
    }

    return 0;
}