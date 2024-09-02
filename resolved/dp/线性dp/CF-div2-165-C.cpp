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
#define INF (ll)(1e18)
using namespace std;
// set<int>::iterator it;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 3);
    vector<vector<int>> dp(n + 3, vector<int>(k + 3, INF));
    f(i, 1, n)
    {
        cin >> a[i];
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= min(i - 1, k); j++) // 使用了j次
        {
            for (int tt = 0; tt <= j; tt++) // 以a[i]为中心，左边有tt个数连续使用
            {
                int minn = a[i];
                for (int fuck = i - tt; fuck <= i; fuck++)
                {
                    minn = min(minn, a[fuck]);
                }
                dp[i][j] = min(dp[i][j], dp[i - tt - 1][j - tt] + (tt + 1) * minn);
            }
        }
    }
    auto it = *min_element(dp[n].begin(), dp[n].begin() + k + 1);
    cout << it << endl;
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