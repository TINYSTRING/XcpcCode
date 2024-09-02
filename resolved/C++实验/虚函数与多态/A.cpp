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
// 定义抽象基类Shape
class Shape
{
  public:
    virtual double area() const = 0;
};
class Circle : public Shape
{
  public:
    Circle(double r) : radius(r)
    {
    }
    double area() const override
    {
        return 3.14159 * radius * radius;
    }

  private:
    double radius;
};
class Square : public Shape
{
  public:
    Square(double s) : side(s)
    {
    }
    double area() const override
    {
        return side * side;
    }

  private:
    double side;
};
class Rectangle : public Shape
{
  public:
    Rectangle(double l, double w) : length(l), width(w)
    {
    }
    double area() const override
    {
        return length * width;
    }

  private:
    double length;
    double width;
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Shape* p[3];
        double r;
        cin >> r;
        p[0] = new Circle(r);
        double s;
        cin >> s;
        p[1] = new Square(s);
        double l, w;
        cin >> l >> w;
        p[2] = new Rectangle(l, w);
        for (int i = 0; i < 3; i++)
        {
            cout << fixed << setprecision(2) << p[i]->area() << endl;
        }
    }

    return 0;
}