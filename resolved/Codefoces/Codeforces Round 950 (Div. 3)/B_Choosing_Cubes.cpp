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
    int n, f, k;
    cin >> n >> f >> k;
    f--,k--;
    vector<int> v(n);
    int tmp = 0;
    for (auto& x : v)
    {
        cin >> x;
    }
    tmp = v[f];
    sort(all(v), [](int a, int b) { return a > b; });
    int left = lower_bound(all(v), tmp, greater<int>()) - v.begin();
    int right = upper_bound(all(v), tmp, greater<int>()) - v.begin();
    right--;
    if (left <= k && right > k)
    {
        cout << "MAYBE" << endl;
    }
    else if (right <= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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