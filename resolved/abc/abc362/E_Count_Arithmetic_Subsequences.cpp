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
int dp[100][100][100];
int ans;
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 5);
    f(i, 1, n)
    {
        cin >> a[i];
    }
    // dp[i][j][k]i为首项，j为第二项，k为长度(或者dp[i][j][k]i为倒二项，j为最后一项，k为长度)
    // dp[i][j][k]=dp[i][j][k]+dp[j][l][k-1];(i<j<l)
    f(i, 1, n)
    {
        f(j, i + 1, n)
        {
            dp[i][j][2] = 1;
        }
    }
    f(k, 3, n)
    {
        f(i, 1, n)
        {
            f(j, i + 1, n)
            {
                f(l, j + 1, n)
                {
                    if (a[i] + a[l] == 2 * a[j])
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[j][l][k - 1]) % mod;
                    }
                }
            }
        }
    }
    cout<<n<<" ";
    f(k,2,n)
    {
        int ans=0;
        f(i,1,n)
        {
            f(j,1,n)
            {
                ans=(ans+dp[i][j][k])%mod;
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}