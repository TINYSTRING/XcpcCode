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
    map<char, int> mp;
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (auto& x : s)
    {
        mp[x]++;
    }
    int ans = 0;
    f(i, 0, 6)
    {
        if (mp['A' + i] < m)
        {
            ans += m - mp['A' + i];
        }
    }
    cout << ans << endl;
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