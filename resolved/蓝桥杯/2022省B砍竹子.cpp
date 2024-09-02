#include <bits/stdc++.h>
#include <cmath>
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
#define mod 100000007
#define maxn (ll)(2e5 + 5000)
#define INF LONG_LONG_MAX
using namespace std;
// set<int>::iterator it;
int h[maxn] = {0};
int temp[maxn] = {0};
void solve()
{
    int n;
    cin >> n;
    int maxtime = 0;
    f(i, 1, n)
    {
        cin >> h[i];
        int t = h[i];
        while (t - 1)
        {
            temp[i]++;
            t = sqrt(t / 2 + 1);
        }
        maxtime = max(maxtime, temp[i]);
    }
    int ans = 0;
    ff(i, maxtime, 1)
    {
        f(j, 1, n)
        {
            if (temp[j] == i)
            {
                if (h[j] != h[j + 1])
                {
                    ans++;
                }
                temp[j]--;
                h[j]=sqrt(h[j]/2+1);
            }
        }
    }
    cout << ans << endl;
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}