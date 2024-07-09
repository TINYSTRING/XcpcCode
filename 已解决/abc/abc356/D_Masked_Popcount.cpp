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
#define mod 998244353
#define maxn (ll)(2e5 + 5000)
#define INF LONG_LONG_MAX
using namespace std;
// set<int>::iterator it;

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    f(i, 0, 61)
    {
        if (m >> i & 1)
        {
            int cnt1 = (n >> (i + 1)) << i;
            int cnt2 = max(n % (1LL << (i + 1)) - (1LL << i) + 1, 0LL); // 周期为0~2^(i+1)-1
            ans = (ans % mod + cnt1 % mod + cnt2 % mod) % mod;
        }
    }
    cout << ans % mod << endl;

    return 0;
}