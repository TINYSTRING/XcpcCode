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
map<int, string> mp;
void init()
{
    mp[1] = "黑胶片";
    mp[2] = "CD";
    mp[3] = "VCD";
    mp[4] = "DVD";
    return;
}
class yingxiang
{
  private:
    int type;
    string name;
    int price;
    int staus;

  public:
    yingxiang(int type, string name, int price, int staus) : type(type), name(name), price(price), staus(staus)
    {
    }
    void print()
    {
        cout << mp[type] << "[" << name << "]";
        if (staus == 1)
            cout << "已出租" << endl;
        else
            cout << "未出租" << endl;
    }
    void rent(int q)
    {
        int ans = price * q;
        if (staus==0)
        {
            cout << "未产生租金" << endl;
        }
        else
        {
            cout << "当前租金为" << ans << endl;
        }
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int type;
        string name;
        int price;
        int staus;
        cin >> type >> name >> price >> staus;
        yingxiang yx(type, name, price, staus);
        int q;
        cin >> q;
        if (q == 0)
        {
            yx.print();
        }
        else
        {
            yx.print();
            yx.rent(q);
        }
    }

    return 0;
}