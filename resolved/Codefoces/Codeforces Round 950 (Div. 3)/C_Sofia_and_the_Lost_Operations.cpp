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
void solve()
{
    map<int, int> vis;
    map<int, int> check;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a)
    {
        cin >> x;
    }
    for (auto& x : b)
    {
        cin >> x;
        check[x]++;
    }
    int siz = 0;
    f(i, 0, n - 1)
    {
        if (a[i] != b[i])
        {
            vis[b[i]]++;
            siz++;
        }
    }
    int m;
    cin >> m;
    vector<int> d(m);
    int cnt = 0;
    for (auto& x : d)
    {
        cin >> x;
        if (vis[x] == 0)
        {
            if (check[x] == 0)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
        }
        else
        {
            vis[x]--;
            siz--;
            cnt = 0;
        }
    }
    if (cnt || siz)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}