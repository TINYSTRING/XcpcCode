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
    int l, r, p;
    cin >> l >> r >> p;
    DSU dsu(r + 1);

    vector<vector<int>> vis(r+1);
    f(i, l, r)
    {
        // 分解质因数
        int x = i;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                while (x % j == 0)
                {
                    x /= j;
                }
                if (j >= p)
                {
                    vis[j].pb(i);
                }
            }
        }
        if (x != 1 && x >= p)
        {
            vis[x].pb(i);
        }
    }
    for (int i = p; i <= r; i++)
    {
        if(vis[i].size()==0)
        {
            continue;
        }
        for (int j = 0; j < vis[i].size(); j++)
        {
            dsu.merge(vis[i][0], vis[i][j]);
        }
    }
    int ans = 0;
    f(i,l,r)
    {
        if(dsu.find(i)==i)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}