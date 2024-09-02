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
#define INF LONG_LONG_MAX - 1
using namespace std;
// set<int>::iterator it;

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    vector<int> dp(n + 1);
    dp.assign(n + 1, -INF);
    dp[0] = 0;
    f(i, 0, 2)
    {
        f(j, a[i], n)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + 1);
        }
    }
    cout << dp[n] << endl;

    return 0;
}