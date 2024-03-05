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
#define INF 0x3f3f3f3f
using namespace std;
// set<int>::iterator it;
pii edge;
vector<pii> g[maxn];//存储要到的顶点和距离
priority_queue<pii, vector<pii>, greater<pii>> q;
int dist[maxn];
int pre[maxn];
void dijstra(int s)
{
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (du > dist[u])
            continue;
        for (auto x : g[u])
        {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w)
            {
                pre[v] = u;// 存储父节点，以便打印具体路径
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
        
    }
    return ;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    memset(dist, 0x3f, sizeof(dist));//初始化
    int n, m,s;
    cin >> n >> m>>s;
    f(i, 0, m - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijstra(s);
    f(i,1,n)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
}