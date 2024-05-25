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
class BaseAccount
{
  protected:
    string name;
    string account;
    int balance;

  public:
    BaseAccount(string n, string a, int b) : name(n), account(a), balance(b){};
    virtual void deposit(int money)
    {
        balance += money;
    }
    virtual void withdraw(int money)
    {
        if (balance < money)
        {
            cout << "insufficient" << endl;
        }
        else
        {
            balance -= money;
        }
    }
    virtual void display()
    {
        cout << name << " " << account << " Balance:" << balance << endl;
    }
};
class BasePlus : public BaseAccount
{
  protected:
    int top = 5000;
    int limitSum = 5000;

  public:
    BasePlus(string n, string a, int b) : BaseAccount(n, a, b){};
    void deposit(int money)
    {
        balance += money;
    }
    void withdraw(int money)
    {
        if (balance < money)
        {
            if (balance + limitSum < money)
            {
                cout << "insufficient" << endl;
            }
            else
            {
                limitSum = balance + limitSum - money;
                balance = 0;
            }
        }
        else
        {
            balance -= money;
        }
    }
    void display()
    {
        cout << name << " " << account << " Balance:" << balance << " limit:" << limitSum << endl;
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string name, account;
        int balance;
        cin >> name >> account >> balance;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        BaseAccount* p;
        if (account[1] == 'A')
        {
            p = new BaseAccount(name, account, balance);
            p->deposit(a);
            p->withdraw(b);
            p->deposit(c);
            p->withdraw(d);
            p->display();
        }
        else
        {
            p = new BasePlus(name, account, balance);
            p->deposit(a);
            p->withdraw(b);
            p->deposit(c);
            p->withdraw(d);
            p->display();
        }
    }

    return 0;
}