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
    int s, p;
    cin >> s >> p;
    vector<pii> a(p);
    f(i, 0, p - 1)
    {
        cin >> a[i].first >> a[i].second;
    }
    vector<tuple<int, int, int>> edge;
    f(i, 0, p - 1)
    {
        f(j, i + 1, p - 1)
        {
            int x = a[i].first - a[j].first;
            int y = a[i].second - a[j].second;
            edge.push_back({x * x + y * y, i, j});
        }
    }
    sort(all(edge));
    DSU dsu(p);
    // 最小生成树
    int ans = 0;
    for (auto [d, x, y] : edge)
    {
        if (dsu.merge(x, y)) // 合并成功
        {
            ans++;
        }
        if (ans == p - s)
        {
            cout << fixed << setprecision(2) << sqrt(d) << endl;
            break;
        }
    }

    return 0;
}