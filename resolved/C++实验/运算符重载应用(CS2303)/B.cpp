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
class CMoney
{
    int yuan, jiao, fen;

  public:
    CMoney(int yuan, int jiao, int fen)
    {
        this->yuan = yuan;
        this->jiao = jiao;
        this->fen = fen;
    }
    CMoney(const CMoney& a)
    {
        yuan = a.yuan;
        jiao = a.jiao;
        fen = a.fen;
    }
    friend CMoney operator+(CMoney& a, CMoney& b);
    friend CMoney operator-(CMoney& a, CMoney& b);
    // 重载输入输出
    friend istream& operator>>(istream& in, CMoney& a);
    friend ostream& operator<<(ostream& out, CMoney& a);
};
CMoney operator+(CMoney& a, CMoney& b)
{
    CMoney temp(0, 0, 0);
    temp.yuan = a.yuan + b.yuan;
    temp.jiao = a.jiao + b.jiao;
    temp.fen = a.fen + b.fen;
    if (temp.fen >= 10)
    {
        temp.jiao += temp.fen / 10;
        temp.fen %= 10;
    }
    if (temp.jiao >= 10)
    {
        temp.yuan += temp.jiao / 10;
        temp.jiao %= 10;
    }
    return temp;
}
CMoney operator-(CMoney& a, CMoney& b)
{
    CMoney temp(0, 0, 0);
    temp.yuan = a.yuan - b.yuan;
    temp.jiao = a.jiao - b.jiao;
    temp.fen = a.fen - b.fen;
    if (temp.fen < 0)
    {
        temp.jiao--;
        temp.fen += 10;
    }
    if (temp.jiao < 0)
    {
        temp.yuan--;
        temp.jiao += 10;
    }
    return temp;
}
istream& operator>>(istream& in, CMoney& a)
{
    in >> a.yuan >> a.jiao >> a.fen;
    return in;
}
ostream& operator<<(ostream& out, CMoney& a)
{
    out << a.yuan << "元" << a.jiao << "角" << a.fen <<"分"<<endl;
    return out;
}

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        CMoney a(x, y, z);
        while (1)
        {
            string opt;
            cin >> opt;
            if (opt == "stop")
            {
                break;
            }
            int x1, y1, z1;
            cin >> x1 >> y1 >> z1;
            CMoney b(x1, y1, z1);
            if (opt == "add")
            {
                a = a + b;
            }
            else
            {
                a = a - b;
            }        }
        cout << a;
    }

    return 0;
}