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
    // 最小生成树
    vector<tuple<int, int, int>> edges;
    f(i, 1, m)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.pb({z, x, y});
    }
    sort(all(edges));
    DSU dsu(n + 1);
    for (auto [z, x, y] : edges)
    {
        dsu.merge(x, y);
        if (dsu.size(dsu.find(x)) == n)
        {
            cout << z << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}