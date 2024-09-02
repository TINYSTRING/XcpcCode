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
    vector<int> v(n + 1);
    vector<int> dp(m + 1, 0); // dp[i]表示容量为i的背包最多有多少种方法装满
    f(i, 1, n)
    {
        cin >> v[i];
    }
    dp[0] = 1;
    f(i, 1, n)
    {
        ff(j, m, 0)
        {
            if (j >= v[i])
            {
                dp[j] += dp[j - v[i]];
            }
        }
    }
    cout << dp[m] << endl;

    return 0;
}