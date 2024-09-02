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
// 存在情况，如果所有的钱都买最小价格商品，相比购买最大价格商品省下的钱也无法再购买一个最小价格商品
// 二维费用背包问题
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1);
    int minv = INF;
    f(i, 1, n)
    {
        cin >> v[i] >> w[i];
        minv = min(minv, v[i]);
    }
    int sumv = 0;
    f(i, 1, n)
    {
        v[i] -= minv;
        sumv += v[i];
    }
    // 最多花费j元在前i个物品中选择物品购买，选了k个物品能获得的最大重要度和
    vector<vector<int>> dp(sumv + 1, vector<int>(n + 1, 0));
    f(i, 1, n) // 前i个商品
    {
        ff(j, sumv, v[i]) // j表示花费的钱
        {
            ff(k, n, 1) // k表示购买的商品数量
            {
                if (k * minv + j <= m)// 买k个商品花费的钱
                {
                    dp[j][k] = max(dp[j][k], dp[j - v[i]][k - 1] + w[i]);
                }
            }
        }
    }
    int ans = 0;
    f(i, 0, sumv)
    {
        f(j, 0, n)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}