#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int long long
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
class Metal
{
  protected:
    int h; // 硬度
    int w; // 重量
    int v; // 体积
  public:
    Metal(int hh, int ww, int vv) : h(hh), w(ww), v(vv)
    {
    }
    void print()
    {
        // 硬度8--重量8000--体积800
        cout << "硬度" << h << "--" << "重量" << w << "--" << "体积" << v << endl;
    }
    // 重载"+"号
    friend Metal operator+(Metal& a, Metal& b)
    {
        return Metal(a.h + b.h, a.w + b.w, a.v + b.v);
    }
    // 重载"*"号
    friend Metal operator*(Metal& a, int n)
    {
        return Metal(a.h, a.w, a.v * n);
    }
    // “++”前增量
    Metal operator++()
    {
        h++;
        w *= 1.1;
        v *= 1.1;
        return *this;
    }
    Metal operator--(int)
    {
        Metal temp = *this;
        h--;
        w *= 0.9;
        v *= 0.9;
        return temp;
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int h1, w1, v1;
        int h2, w2, v2;
        cin >> h1 >> w1 >> v1;
        cin >> h2 >> w2 >> v2;
        Metal m1(h1, w1, v1);
        Metal m2(h2, w2, v2);
        Metal m3 = m1 + m2;
        m3.print();
        int n;
        cin >> n;
        Metal m4 = m1 * n;
        m4.print();
        ++m1;
        m1.print();
        m2--;
        m2.print();
    }

    return 0;
}