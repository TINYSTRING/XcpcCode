#include <bits/stdc++.h>
#include <string>
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
class Hotel
{
  private:
    static int totalCustNum;   // 顾客总人数
    static float totalEarning; // 旅店总收入
    static float rent;         // 每个顾客的房租
    string customerName;       // 顾客姓名
    int customerId;            // 顾客编号
  public:
    // totalCustNum++，customerId按照totalCustNum生成
    Hotel(){}; // 默认构造函数
    Hotel(string customer) : customerName(customer)
    {
        totalCustNum++;
        totalEarning = rent * totalCustNum;
        customerId = totalCustNum;
        customerId += 20150000;
    }
    ~Hotel(){};                   // 记得delete customerName
    static void setRent(float r); // 设置每个顾客的房租
    void Display()
    {
        cout << customerName << " " << customerId << " " << totalCustNum << " " << totalEarning << endl;
    }; // 相应输出顾客姓名、顾客编号、总人数、总收入
};
float Hotel::rent = 0;
int Hotel::totalCustNum = 0;
float Hotel::totalEarning = 0;
void Hotel::setRent(float r)
{
    rent = r;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    float fuck;
    cin >> fuck;
    Hotel::setRent(fuck);
    string s;
    while (1)
    {
        cin >> s;
        if (s[0] == '0')
        {
            break;
        }
        Hotel obj(s);
        obj.Display();
    }

    return 0;
}