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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    int sum1 = 0, sum2 = 0;
    f(i, 0, n - 1)
    {
        cin >> a[i] >> b[i];
        sum1 += a[i];
        sum2 += b[i];
    }
    if (sum1 <= x && sum2 <= y)
    {
        cout << n << endl;
        return 0;
    }
    // 二维费用背包问题
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(
                   n + 1, vector<int>(y + 1, 1e9))); // dp[i][j][k]表示前i个物品中最多选j个，总体积为k的最小甜度
    dp[0][0][0] = 0;
    f(i, 0, n - 1)
    {
        f(j, 0, i)
        {
            f(k, 0, y)
            {
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]); // 不选第i个物品
                if (k + b[i] <= y)                                   // 选第i个物品
                {
                    dp[i + 1][j + 1][k + b[i]] = min(dp[i + 1][j + 1][k + b[i]], dp[i][j][k] + a[i]); // 选第i个物品
                }
            }
        }
    }

    ff(i, n, 0) // 枚举选的物品数量
    {
        f(j, 0, y)
        {
            if (dp[n][i][j] <= x)
            {
                cout << i + 1 << endl; // 选的物品数量
                return 0;
            }
        }
    }
    return 0;
}