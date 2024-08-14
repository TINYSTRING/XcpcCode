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

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(m + 1), w(m + 1);
    f(i, 1, m)
    {
        cin >> v[i] >> w[i];
    }
    vector<int> dp(n + 1, 0);
    f(i, 1, m)
    {
        ff(j, n, v[i])
        {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i] * w[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}