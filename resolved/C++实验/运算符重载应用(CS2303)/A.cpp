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
class point
{
    int x, y, z;

  public:
    point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    point(const point& a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
    }
    friend point operator++(point& a);      // 前置
    friend point operator++(point& a, int); // 后置
    friend point operator--(point& a);      // 前置
    friend point operator--(point& a, int); // 后置
    void show()
    {
        cout << "x=" << x << " y=" << y << " z=" << z << endl;
    }
};
point operator++(point& a)
{
    a.x++;
    a.y++;
    a.z++;
    return a;
}
point operator++(point& a, int)
{
    point temp = a;
    a.x++;
    a.y++;
    a.z++;
    return temp;
}
point operator--(point& a)
{
    a.x--;
    a.y--;
    a.z--;
    return a;
}
point operator--(point& a, int)
{
    point temp = a;
    a.x--;
    a.y--;
    a.z--;
    return temp;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int x, y, z;
    cin >> x >> y >> z;
    point p1(x, y, z);
    point p2 = p1++;
    p1.show();
    p2.show();
    p1--;
    p2 = ++p1;
    p1.show();
    p2.show();
    p1--;
    p2 = p1--;
    p1.show();
    p2.show();
    p1++;
    p2 = --p1;
    p1.show();
    p2.show();
    return 0;
}