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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a, b;
        f(i, 1, n)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
            {
                a.pb(x); // 偶数
            }
            else
            {
                b.pb(x); // 奇数
            }
        }
        if (a.size() == 0 || b.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int tmp = *max_element(all(b));
        sort(all(a));
        int ans = 0;
        int tt = a.size() - 1;
        f(i, 0, tt)
        {
            if (tmp < a[i])
            {
                ans += 2;
                tmp = tmp + a[tt] * 2;
                if (i != tt)
                {
                    ans++;
                    tmp = tmp + a[i];
                }
                tt--;
            }
            else
            {
                ans++;
                tmp = a[i] + tmp;
            }
        }
        cout << ans << endl;
    }

    return 0;
}