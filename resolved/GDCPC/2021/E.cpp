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
bool check1(int x1, int y1, int z1, int x2, int y2, int z2) // 1000*z=x^2+y^2
{
    int t1 = x1 * x1 + y1 * y1;
    int t2 = x2 * x2 + y2 * y2;
    int t3 = z1*1000;
    int t4 = z2*1000;
    if (((t3 > t1) != (t4 > t2)) || (((-1*t3) > t1) != ((-1*t4) > t2)))
    {
        return true;
    }
    return false;
}
bool check2(int x1, int y1, int z1, int x2, int y2, int z2) // 1000*y=x^2+z^2
{
    int t1 = x1 * x1 + z1 * z1;
    int t2 = x2 * x2 + z2 * z2;
    int t3 = y1*1000;
    int t4 = y2*1000;
    if (((t3 > t1) != (t4 > t2)) || (((-1*t3) > t1) != ((-1*t4) > t2)))
    {
        return true;
    }
    return false;
}
bool check3(int x1, int y1, int z1, int x2, int y2, int z2) // 1000*x=y^2+z^2
{
    int t1 = y1 * y1 + z1 * z1;
    int t2 = y2 * y2 + z2 * z2;
    int t3 = x1*1000;
    int t4 = x2*1000;
    if (((t3 > t1) != (t4 > t2)) || (((-1*t3) > t1) != ((-1*t4) > t2)))
    {
        return true;
    }
    return false;
}

void solve()
{
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    if (check1(x1, y1, (z1), x2, y2, (z2)) || check2(x1, (y1), z1, x2, (y2), z2) || check3((x1), y1, z1, (x2), y2, z2))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}