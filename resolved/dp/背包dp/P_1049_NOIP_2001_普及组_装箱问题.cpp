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
    int v, n;
    cin >> v >> n;
    vector<int> w(n + 1), dp(v + 1, 0);
    f(i, 1, n)
    {
        cin >> w[i];
    }
    f(i, 1, n)
    {
        ff(j, v, 0)
        {
            if (j >= w[i])
            {
                dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
            }
        }
    }
    cout << v - dp[v] << endl;

    return 0;
}