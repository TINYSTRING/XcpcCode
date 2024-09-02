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
#define maxn (ll)(2e6 + 5000)
#define INF LONG_LONG_MAX
using namespace std;
// set<int>::iterator it;
// 普通并查集
// struct DSU
// {
//     vector<int> f, siz;
//     DSU(){};
//     DSU(int n)
//     {
//         f.resize(n);
//         iota(all(f), 0);
//         siz.assign(n, 1);
//     }
//     int find(int x)
//     {
//         while (x != f[x])
//         {
//             x = f[x] = f[f[x]];
//         }
//         return x;
//     }
//     bool same(int x, int y)
//     {
//         return find(x) == find(y);
//     }
//     bool merge(int x, int y)
//     {
//         x = find(x), y = find(y);
//         if (x == y)
//         {
//             return false;
//         }
//         // if (siz[x] < siz[y])
//         // {
//         //     swap(x, y);
//         // }
//         siz[x] += siz[y];
//         f[y] = x;
//         return true;
//     }
//     int size(int x)
//     {
//         return siz[find(x)];
//     }
// };
// 带权并查集
// struct DSU
// {
//     vector<int> f, siz, w;
//     DSU(){};
//     DSU(int n)
//     {
//         f.resize(n);
//         iota(all(f), 0);
//         siz.assign(n, 1);
//         w.assign(n, 0);
//     }
//     int find(int x)
//     {
//         if (x == f[x])
//         {
//             return x;
//         }
//         int fa = find(f[x]);
//         w[x] += w[f[x]];
//         return f[x] = fa;
//     }
//     bool merge(int x, int y)//将x合并到y
//     {
//         int fx = find(x), fy = find(y);
//         if (fx == fy)
//         {
//             return false;
//         }
//         f[fx] = fy;
//         w[fx] = siz[fy];
//         siz[fy] += siz[fx];
//         return true;
//     }
//     bool same(int x, int y)
//     {
//         return find(x) == find(y);
//     }
// };
struct DSU
{
    vector<int> f, siz, w;
    DSU(){};
    DSU(int n)
    {
        f.resize(n);
        iota(all(f), 0);//iota函数用于给定范围内的元素赋值
        siz.assign(n, 1);
        w.assign(n, 0);
    }
    int find(int x)
    {
        {
            w[x] += w[f[x]];
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool merge(int x, int y) // 将x合并到y
    {
        int fx = find(x), fy = find(y);
        if (fx == fy)
        {
            return false;
        }
        f[fx] = fy;         // 修改根节点
        w[fx] = siz[fy];    // 修改权值
        siz[fy] += siz[fx]; // 修改大小
        return true;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    DSU dsu(maxn);
    f(times, 1, t)
    {
        char opt;
        cin >> opt;
        int i, j;
        cin >> i >> j;
        if (opt == 'M')
        {
            dsu.merge(i, j);
        }
        else if (opt == 'C')
        {
            if (dsu.same(i, j))
            {
                cout << abs(dsu.w[i] - dsu.w[j]) - 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}