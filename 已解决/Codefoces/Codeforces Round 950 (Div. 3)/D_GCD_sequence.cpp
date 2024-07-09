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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
    {
        cin >> i;
    }
    vector<int> tmp;
    f(i, 0, n - 2)
    {
        tmp.pb(gcd(a[i], a[i + 1]));
    }
    int bad = 0;
    f(i, 0, n - 3)
    {
        bad += (tmp[i] > tmp[i + 1]);
    }
    if(bad==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    if (tmp[0] > tmp[1] || tmp[n - 3] > tmp[n - 2])
    {
        if (bad == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    f(i, 1, n - 2)
    {
        int fuck = bad;
        fuck -= (tmp[i - 1] > tmp[i]);
        int temp = gcd(a[i - 1], a[i + 1]);
        if (i - 1 > 0)
        {
            fuck += (temp < tmp[i - 2]);
            fuck -= (tmp[i - 2] > tmp[i - 1]);
        }
        if (i + 1 < n - 1)
        {
            fuck += (temp > tmp[i + 1]);
            fuck -= (tmp[i] > tmp[i + 1]);
        }
        if (fuck==0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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