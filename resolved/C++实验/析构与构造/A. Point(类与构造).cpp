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
#define mod 100000007
#define maxn (ll)(2e5 + 5000)
#define INF LONG_LONG_MAX
using namespace std;
// set<int>::iterator it;
class Point
{
    double x, y;

  public:
    Point();
    Point(double x, double y);
    double getx();
    double gety();
    void setx(double x);
    void sety(double y);
    double distance(Point p);
};
Point::Point()
{
    x = 0;
    y = 0;
}
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}
double Point::getx()
{
    return x;
}
double Point::gety()
{
    return y;
}
void Point::setx(double x)
{
    this->x = x;
}
void Point::sety(double y)
{
    this->y = y;
}
double Point::distance(Point p)
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}
void solve()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1), p2(x2, y2);
    // 输出：Distance of Point(1.00,2.00) to Point(3.00,4.00) is 2.83
    cout << "Distance of Point(" << fixed << setprecision(2) << p1.getx() << "," << p1.gety() << ") to Point("
         << p2.getx() << "," << p2.gety() << ") is " << p1.distance(p2) << endl;
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