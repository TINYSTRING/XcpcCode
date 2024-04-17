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
/*
某个类包含一个整型数据成员.程序运行时若输入0表示用缺省方式定义一个类对象;输入1及一个整数表示用带一个参数的构造函数构造一个类对象;
输入2及一个整数表示构造2个类对象，一个用输入的参数构造，另一个用前一个对象构造。试完成该类的定义和实现。*/
class MyClass
{
  public:
    // 默认构造函数
    MyClass() : num(0){};
    // 带一个参数的构造函数
    MyClass(int n) : num(n){};
    // 拷贝构造函数
    MyClass(const MyClass& obj) : num(obj.num){};
    // 获取整型数据成员的值
    int getNum() const
    {
        return num;
    }
  private:
    int num; // 整型数据成员
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {

            cout << "Constructed by default, value = " << MyClass().getNum() << endl;
        }
        else if (x == 1)
        {
            int n;
            cin >> n;
            cout << "Constructed using one argument constructor, value = " << MyClass(n).getNum() << endl;
        }
        else if (x == 2)
        {
            int n;
            cin >> n;
            MyClass obj1(n);
            MyClass obj2(obj1);
            cout << "Constructed using one argument constructor, value = " << obj1.getNum() << endl;
            cout << "Constructed using copy constructor, value = " << obj2.getNum() << endl;
        }
    }

    return 0;
}