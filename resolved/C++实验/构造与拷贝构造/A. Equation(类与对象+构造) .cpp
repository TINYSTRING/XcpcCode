#include <bits/stdc++.h>
#include <ios>
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
class Equation
{
  private:
    double a, b, c;

  public:
    Equation()
    {
        a = 1.0;
        b = 1.0;
        c = 0;
    };
    // set方法，用于修改a、b、c的值
    void set(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    };
    // getRoot方法，用于求解方程的根
    void getRoot()
    {
        double delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            // 复数根
            // 保留两位小数
            cout << "x1=" << fixed << setprecision(2) << -b / (2 * a) << "+" << sqrt(-delta) / (2 * a) << "i"<<" ";
            cout << "x2=" << -b / (2 * a) << "-" << fixed << setprecision(2) << sqrt(-delta) / (2 * a) << "i" << endl;
        }
        else if (delta == 0)
        {
            // 保留两位小数
            cout << "x1=x2=" << fixed << setprecision(2) << -b / (2 * a) << endl;
        }
        else
        {
            cout << "x1=" << fixed << setprecision(2) << (-b + sqrt(delta)) / (2 * a)<<" ";
            cout << "x2=" << fixed << setprecision(2) << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    };
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Equation e;
        double a, b, c;
        cin >> a >> b >> c;
        e.set(a, b, c);
        e.getRoot();
    }

    return 0;
}