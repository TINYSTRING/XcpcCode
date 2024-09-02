#include <bits/stdc++.h>
#include <iostream>
#define endl '\n'
#define ll long long
#define int long long
#define pii pair<int, int>
#define pb push_back
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
/*完成下列分数类的实现:

class CFraction
{
private:
     int fz, fm;
public:
     CFraction(int fz_val, int fm_val) ;
     CFraction add(const CFraction &r);
     CFraction sub(const CFraction &r);
     CFraction mul(const CFraction &r);
     CFraction div(const CFraction &r);
     int getGCD();   // 求对象的分子和分母的最大公约数
     void print();
};

求两数a、b的最大公约数可采用辗转相除法，又称欧几里得算法，其步骤为:

1. 交换a, b使a > b;
2. 用a除b得到余数r,若r=0,则b为最大公约数,退出.
3. 若r不为0,则用b代替a, r代替b,此时a,b都比上一次的小,问题规模缩小了;
4. 继续第2步。

注意：如果分母是1的话，也按“分子/1”的方式输出。*/
class CFraction
{
  private:
    int fz, fm;

  public:
    CFraction(int fz_val, int fm_val);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    int getGCD(int a, int b); // 求两数的最大公约数
    void print();
};

CFraction::CFraction(int fz_val, int fm_val)
{
    fz = fz_val;
    fm = fm_val;
}

int CFraction::getGCD(int a, int b)
{
    if (a < b)
        swap(a, b);
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

CFraction CFraction::add(const CFraction& r)
{
    int a = fz * r.fm + r.fz * fm;
    int b = fm * r.fm;
    int gcd = getGCD(a, b);
    return CFraction(a / gcd, b / gcd);
}

CFraction CFraction::sub(const CFraction& r)
{
    int a = fz * r.fm - r.fz * fm;
    int b = fm * r.fm;
    int gcd = getGCD(a, b);
    return CFraction(a / gcd, b / gcd);
}

CFraction CFraction::mul(const CFraction& r)
{
    int a = fz * r.fz;
    int b = fm * r.fm;
    int gcd = getGCD(a, b);
    return CFraction(a / gcd, b / gcd);
}

CFraction CFraction::div(const CFraction& r)
{
    int a = fz * r.fm;
    int b = fm * r.fz;
    int gcd = getGCD(a, b);
    return CFraction(a / gcd, b / gcd);
}

void CFraction::print()
{
    int gcd = getGCD(abs(fz), abs(fm));
    int a = fz / gcd;
    int b = fm / gcd;
    if (b < 0)
    {
        a = -a;
        b = -b;
    }
    cout << a << "/" << b << endl;
}
void solve()
{
    // 输入两个分数
    int a, b, c, d;
    char ch1, ch2, ch3, ch4;
    cin >> a >> ch1 >> b;
    cin >> c >> ch2 >> d;
    CFraction f1(a, b), f2(c, d);
    // 输出两个分数的和
    CFraction f3 = f1.add(f2);
    f3.print();
    // 输出两个分数的差
    f3 = f1.sub(f2);
    f3.print();
    // 输出两个分数的积
    f3 = f1.mul(f2);
    f3.print();
    // 输出两个分数的商
    f3 = f1.div(f2);
    f3.print();
    cout << endl;
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