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
class Vehicle
{
  protected:
    string no; // 编号
  public:
    virtual void display() const = 0; // 应收费用
};
class Car : virtual public Vehicle
{
  protected:
    int num;    // 载客数
    int weight; // 重量
  public:
    Car(string n, int a, int b) : Vehicle(), num(a), weight(b)
    {
        no = n;
    }
    void display() const override
    {
        cout << no << " " << num * 8 + weight * 2 << endl;
    }
};
class Truck : virtual public Vehicle
{
  protected:
    int weight; // 载重量
  public:
    Truck(string n, int a) : Vehicle(), weight(a)
    {
        no = n;
    }
    void display() const override
    {
        cout << no << " " << weight * 5 << endl;
    }
};
class Bus : virtual public Vehicle
{
  protected:
    int num; // 载客数
  public:
    Bus(string n, int a) : Vehicle(), num(a)
    {
        no = n;
    }
    void display() const override
    {
        cout << no << " " << num * 30 << endl;
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            string n;
            int num, weight;
            cin >> n >> num >> weight;
            Car c(n, num, weight);
            c.display();
        }
        else if (opt == 2)
        {
            string n;
            int weight;
            cin >> n >> weight;
            Truck t(n, weight);
            t.display();
        }
        else
        {
            string n;
            int num;
            cin >> n >> num;
            Bus b(n, num);
            b.display();
        }
    }

    return 0;
}