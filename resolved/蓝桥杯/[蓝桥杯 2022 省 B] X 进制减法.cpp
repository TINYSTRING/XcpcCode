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
int a[maxn] = {0}, b[maxn] = {0}, c[maxn] = {0};
int d[maxn] = {0};
void solve()
{
    int n;
    cin >> n;
    int m1, m2;
    cin >> m1;
    ff(i, m1, 1)
    {
        cin >> a[i];
    }
    cin >> m2;
    ff(i, m2, 1)
    {
        cin >> b[i];
    }
    f(i, 1, max(m1, m2))
    {
        c[i] = max(a[i], b[i]) + 1;
        c[i] = (c[i] > 2 ? c[i] : 2);
    }
    d[1] = 1;
    f(i, 2, max(m1, m2))
    {
        d[i] = d[i - 1] * c[i - 1];
        d[i] %= mod;
    }
    int ans1 = 0, ans2 = 0;
    f(i, 1, m1)
    {
        ans1 += a[i] * d[i];
        ans1 %= mod;
    }
    f(i, 1, m2)
    {
        ans2 += b[i] * d[i];
        ans2 %= mod;
    }
    cout << (ans1 - ans2 + mod) % mod << endl;
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}