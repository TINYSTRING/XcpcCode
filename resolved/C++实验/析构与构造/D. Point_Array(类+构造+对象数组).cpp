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
/*1、增加自写的析构函数；

2、将getDisTo方法的参数修改为getDisTo(const Point &p)；

3、根据输出的内容修改相应的构造函数。

然后在主函数中根据用户输入的数目建立Point数组，求出数组内距离最大的两个点之间的距离值。*/
int n;
class Point
{
    double x, y;

  public:
    Point()
    {
        cout << "Constructor." << endl;
    }
    ~Point()
    {
        cout << "Distructor." << endl;
    }
    double getx();
    double gety();
    void setxy(double x, double y)
    {
        this->x = x;
        this->y = y;
    };
    void setx(double x);
    void sety(double y);
    double distance(const Point& p);
};
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
double Point::distance(const Point& p)
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}
void solve()
{

    cin >> n;
    Point* p = new Point[n];
    double max = 0;
    f(i, 0, n - 1)
    {
        double x, y;
        cin >> x >> y;
        p[i].setxy(x, y);
    }
    int tmp1,tmp2;
    f(i, 0, n - 1)
    {
        f(j, i + 1, n - 1)
        {
            double dis = p[i].distance(p[j]);
            if (dis > max)
            {
                max = dis;
                tmp1=i;
                tmp2=j;
            }
        }
    }
    if(tmp1>tmp2)
    {
        swap(tmp1,tmp2);
    }
    ////输出：The longest distance is 17.03,between p[0] and p[1].
    cout << "The longest distance is " << fixed << setprecision(2) << max << ",between p[" << tmp1 << "] and p[" << tmp2 << "]." << endl;
    delete[] p;
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