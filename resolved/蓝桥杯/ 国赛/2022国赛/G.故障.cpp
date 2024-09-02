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
long double P[maxn];
long double p[100][100];
pair<int,long double> ans[maxn];
int vis[maxn];
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    f(i, 1, n)
    {
        cin >> P[i];
    }
    f(i, 1, n)
    {
        f(j, 1, m)
        {
            cin >> p[i][j];
        }
    }
    int k;
    cin >> k;
    f(i, 1, k)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    long double sum = 0;
    f(i, 1, n)
    {
        ans[i].first = i;
        ans[i].second = P[i];
        f(j, 1, m)
        {
            if (vis[j])
            {
                ans[i].second *= p[i][j];
            }
            else
            {
                ans[i].second *= (100 - p[i][j]);
            }
        }
        sum += ans[i].second;
    }
    sort(ans + 1, ans + n + 1, [](pair<int,long double>a,pair<int,long double>b) { if(a.second==b.second){return a.first<b.first;}else{return a.second>b.second;} });
    f(i, 1, n)
    {
        cout << ans[i].first << " " << fixed << setprecision(2) << (ans[i].second / sum * 100) << endl;
    }

    return 0;
}