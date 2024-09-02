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
#define INF (LONG_LONG_MAX - INT_MAX)
using namespace std;
// set<int>::iterator it;
vector<pii> g[maxn];
int dis[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q; // 小顶堆
bool vis[maxn];
void dijstar(int s)
{
    dis[s] = 0;
    q.push({0, s}); // 距离和点
    while (!q.empty())
    {
        pii t = q.top();
        q.pop();
        int du = t.first;   // 距离
        int u = t.second; // 当前点
        if(vis[u]) continue;
        vis[u]=true;
        for(auto i:g[u])
        {
            auto [v,w]=i;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    fill(dis, dis + maxn, INF);
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    f(i, 1, n)
    {
        cin >> c[i];
    }
    f(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w + c[v]}); // 要到的点和距离
        g[v].pb({u, w + c[u]});
    }
    dijstar(1);
    cout<<dis[n]-c[n]<<endl;

    return 0;
}