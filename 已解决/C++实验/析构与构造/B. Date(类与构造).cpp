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
class Date
{
    int year, month, day;

  public:
    Date();
    Date(int y, int m, int d);
    void getyear();
    void getmonth();
    void getday();
    void setdate(int y, int m, int d);
    void print();
    void addoneday();
};
Date::Date()
{
    year = 2000;
    month = 1;
    day = 1;
}
Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
void Date::getyear()
{
    cout << year << endl;
}
void Date::getmonth()
{
    cout << month << endl;
}
void Date::getday()
{
    cout << day << endl;
}
void Date::setdate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
void Date::print()
{
    // 输出：Today is 2012/03/31
    // 如果为一位数，加上前导0
    cout << "Today is " << year << "/";
    if (month < 10)
    {
        cout << "0";
    }
    cout << month << "/";
    if (day < 10)
    {
        cout << "0";
    }
    cout << day << endl;
    return;
}
// 判断明天的日期
void Date::addoneday()
{
    // 闰年判断
    bool isleap = false;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        isleap = true;
    }
    // 月份判断
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
    {
        if (day == 31)
        {
            day = 1;
            month++;
        }
        else
        {
            day++;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day == 30)
        {
            day = 1;
            month++;
        }
        else
        {
            day++;
        }
    }
    else if (month == 12)
    {
        if (day == 31)
        {
            day = 1;
            month = 1;
            year++;
        }
        else
        {
            day++;
        }
    }
    else if (month == 2)
    {
        if (isleap)
        {
            if (day == 29)
            {
                day = 1;
                month++;
            }
            else
            {
                day++;
            }
        }
        else
        {
            if (day == 28)
            {
                day = 1;
                month++;
            }
            else
            {
                day++;
            }
        }
    }
    cout << "Tomorrow is " << year << "/";
    if (month < 10)
    {
        cout << "0";
    }
    cout << month << "/";
    if (day < 10)
    {
        cout << "0";
    }
    cout << day << endl;
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int y, m, d;
        cin >> y >> m >> d;
        Date date(y, m, d);
        date.print();
        date.addoneday();
    }

    return 0;
}