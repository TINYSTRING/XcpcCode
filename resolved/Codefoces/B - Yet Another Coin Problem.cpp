//Codeforces Round 931 (Div. 2), problem: (B) Yet Another Coin Problem
#include <bits/stdc++.h>
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
#define INF (ll)(1e18 + 7)
using namespace std;
// set<int>::iterator it;
int a[10] = {INF, 15, 10, 6, 3, 1};
int n;
map<int, int> mp;
void solve()
{
    cin >> n;
    int mf = 0;
    if (n > 30)
    {
        mf = (n / 15) - 1;
        n -= 15 * mf;//留一点余数+15,给出可操作空间
    }
    else
    {
        cout << mp[n] << endl;
        return;
    }
    cout << mp[n] + mf << endl;
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 1;
    mp[4] = 2;
    mp[5] = 3;
    mp[6] = 1;
    mp[7] = 2;
    mp[8] = 3;
    mp[9] = 2;
    mp[10] = 1;
    mp[11] = 2;
    mp[12] = 2;
    mp[13] = 2;
    mp[14] = 3;
    mp[15] = 1;
    mp[16] = 2;
    mp[17] = 3;
    mp[18] = 2;
    mp[19] = 3;
    mp[20] = 2;
    mp[21] = 2;
    mp[22] = 3;
    mp[23] = 3;
    mp[24] = 3;
    mp[25] = 2;
    mp[26] = 3;
    mp[27] = 3;
    mp[28] = 3;
    mp[29] = 4;
    mp[30] = 2;
    while (t--)
    {
        solve();
    }

    return 0;
}