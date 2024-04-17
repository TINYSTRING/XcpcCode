#include <iostream>
#include <set>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
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
class Account
{
  private:
    static float count; // 账户总余额
    static float interestRate;
    string accno, accname;
    float balance, balance1, banlance2, banlance3;

  public:
    Account(){};
    Account(string ac, string na, float ba)
    {
        accno = ac;
        accname = na;
        balance = ba;
    };
    ~Account();
    void deposit(float amount)
    {
        balance1 = balance + amount;
    }; // 存款
    void withdraw(float amount)
    {
        banlance2 = amount;
    };                  // 取款
    float getBalance(); // 获取账户余额
    friend void update(Account& a);
    void show()
    {
        cout << accno << " " << accname << " " << balance1 << " " << banlance3 << " " << banlance3 - banlance2 << endl;
        count += banlance3 - banlance2;
    };                                       // 显示账户所有基本信息
    static float getCount();                 // 获取账户总余额
    static void setInterestRate(float rate); // 设置利率
    static float getInterestRate();          // 获取利率2
};
float Account::count = 0;
float Account::interestRate = 0;
Account::~Account()
{
}
float Account::getInterestRate()
{
    return interestRate;
}
void Account::setInterestRate(float rate)
{
    interestRate = rate;
    return;
}
float Account::getCount()
{
    return count;
}
void update(Account& a)
{
    a.banlance3 = a.balance1 * (1 + Account::interestRate);
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    float InterestRate;
    cin >> InterestRate;
    Account::setInterestRate(InterestRate);
    int n;
    cin >> n;
    Account* acc = new Account[n];
    int w = 0;
    while (n--)
    {
        string accno, accname;
        float balance;
        cin >> accno >> accname >> balance;
        acc[w++] = Account(accno, accname, balance);
        float a, b;
        cin >> a >> b;
        acc[w - 1].deposit(a);
        acc[w - 1].withdraw(b);
        update(acc[w - 1]);
    }
    f(i, 0, w - 1)
    {
        acc[i].show();
    }
    cout << Account::getCount() << endl;
    return 0;
}