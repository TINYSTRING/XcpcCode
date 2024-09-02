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
class CDate
{
  private:
    int year, month, day;

  public:
    CDate(int y, int m, int d);
    bool isLeapYear(int i);
    int getYear();
    int getMonth();
    int getDay();
    int getDayofYear();
    // 计算year到2015的天数
    int check();
};
CDate::CDate(int y, int m, int d)
{
    year = y, month = m, day = d;
}

bool CDate::isLeapYear(int i)
{
    return (i % 4 == 0 && i % 100 != 0) || i % 400 == 0;
}

int CDate::getYear()
{
    return year;
}

int CDate::getMonth()
{
    return month;
}

int CDate::getDay()
{
    return day;
}
int CDate::getDayofYear()
{
    int i, sum = day;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
    {
        a[2]++;
    }
    // 求日期的天数
    for (i = 0; i < month; i++)
    {
        sum += a[i];
    }
    return sum;
}
int CDate::check()
{
    int sum = 0;
    f(i, 2015, year - 1)
    {
        if (isLeapYear(i))
        {
            sum += 366;
        }
        else
        {
            sum += 365;
        }
    }
    return sum;
}
class CSoftware
{
  private:
    string name, type, storage;
    CDate date;

  public:
    CSoftware(string n, string t, string s, CDate d) : name(n), type(t), storage(s), date(d){};
    CSoftware(const CSoftware& obj) : name(obj.name), type("B"), storage("H"), date(obj.date){};
    void print()
    {
        if (type == "O")
        {
            type = "original";
        }
        else if (type == "T")
        {
            type = "trial";
        }
        else if (type == "B")
        {
            type = "backup";
        }
        if (storage == "D")
        {
            storage = "optical disk";
        }
        else if (storage == "H")
        {
            storage = "hard disk";
        }
        else if (storage == "U")
        {
            storage = "USB disk";
        }
        cout << "name:" << name << endl;
        cout << "type:" << type << endl;
        cout << "media:" << storage << endl;
        if (date.getYear() == 0 && date.getMonth() == 0 && date.getDay() == 0)
        {
            cout << "this software has unlimited use" << endl;
        }
        else if (date.getYear() < 2015 || (date.getYear() == 2015 && date.getMonth() < 4) ||
                 (date.getYear() == 2015 && date.getMonth() == 4 && date.getDay() < 7))
        {
            cout << "this software has expired" << endl;
        }
        else
        {
            cout << "this software is going to be expired in " << date.getDayofYear() - 97 + date.check() << " days"
                 << endl;
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
        string name, type, storage;
        int y, m, d;
        cin >> name >> type >> storage >> y >> m >> d;
        CDate date(y, m, d);
        CSoftware s(name, type, storage, date);
        CSoftware s1(s);
        s.print();
        cout << endl;
        s1.print();
        cout << endl;
    }

    return 0;
}