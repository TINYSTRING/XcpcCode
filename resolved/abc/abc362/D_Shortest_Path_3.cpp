#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
#define gcd __gcd
#define f(i, s, e) for (int i = s; i <= e; i++)
#define ff(i, s, e) for (int i = s; i >= e; i--)
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 100000007
#define maxn (ll)(2e5 + 5000)
using namespace std;
// set<int>::iterator it;
vector<pii> g[maxn];                              // 存储要到的顶点和距离
priority_queue<pii, vector<pii>, greater<pii>> q; // 存储距离和顶点,greater表示小顶堆,默认是大顶堆,q.top()是最小的
int dist[maxn];
void dijstra(int s)
{
    q.push({dist[s], s});
    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first; // 距离
        q.pop();
        if (du > dist[u]) // 如果当前距离大于最短距离
        {
            continue;
        }
        for (auto x : g[u])
        {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    f(i, 0, maxn - 1)
    {
        dist[i] = 4e18;
    }
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 5);
    f(i, 1, n)
    {
        cin >> A[i];
    }
    f(i, 0, m - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w + A[v]});
        g[v].push_back({u, w + A[u]});
    }
    dist[1] = A[1];
    dijstra(1);
    f(i, 2, n)
    {
        cout << dist[i] << " ";
    }

    return 0;
}
