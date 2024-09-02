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
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> check(m + 2),mp(m+2);
    f(i, 1, m)
    {
        int c;
        cin >> c;
        f(j, 1, c)
        {
            int x;
            cin >> x;
            check[i] |= 1 << (x - 1);//check[i] is a mask,which is used to check whether the i-th member is in the group
        }
        char r;
        cin >> r;
        mp[i] = (r == 'o');//if use check[i] as a key,maybe have some member is repeated,so we use mp[i] as a key
    }
    int top = (1 << n) - 1;
    int ans = 0;
    f(i, 0, top)
    {
        int flag = 1;
        f(x, 1, m)
        {
            int cnt = setbits(i & check[x]);
            if ((cnt >= k) != mp[x])
            {
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << endl;

    return 0;
}