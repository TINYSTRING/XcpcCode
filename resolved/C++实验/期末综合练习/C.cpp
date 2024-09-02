/*#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int long long
#define pii pair<int, int>
#define pb push_back
#define gcd __gcd
#define lcm(a,b) (a*b)/gcd(a,b)
#define all(a) a.begin(),a.end()
#define mem(a,x) memset(a,x,sizeof(a))
#define f(i,s,e) for(int i=s;i<=e;i++)
#define ff(i,s,e) for(int i=s;i>=e;i--)
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define maxn (ll)(2e5+5000)
#define INF LONG_LONG_MAX
using namespace std;
//set<int>::iterator it;
using namespace std;

// Date class to manage the date-related information
class CDate {
private:
    int year;
    int month;
    int day;

public:
    CDate(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}

    // Function to calculate the difference in days between two dates
    int differenceInDays(const CDate& other) const {
        int y1 = year, m1 = month, d1 = day;
        int y2 = other.year, m2 = other.month, d2 = other.day;
        static const int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        auto isLeap = [](int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); };
        auto daysInYear = [&](int y) { return isLeap(y) ? 366 : 365; };

        auto daysFromStart = [&](int y, int m, int d) {
            int days = d;
            for (int i = 0; i < m - 1; ++i) days += days_in_month[i];
            if (m > 2 && isLeap(y)) days += 1;
            for (int i = 1; i < y; ++i) days += daysInYear(i);
            return days;
        };

        return daysFromStart(y2, m2, d2) - daysFromStart(y1, m1, d1);
    }

    friend ostream& operator<<(ostream& os, const CDate& date) {
        os << date.year << "-" << setw(2) << setfill('0') << date.month << "-" << setw(2) << setfill('0') << date.day;
        return os;
    }
};

class Pet {
protected:
    string name;
    float length;
    float weight;
    CDate current;

public:
    Pet(const string& n, float l, float w, const CDate& c) : name(n), length(l), weight(w), current(c) {}
    virtual ~Pet() = default;
    virtual void display(const CDate& day) = 0;
};

class Cat : public Pet {
public:
    Cat(const string& n, float l, float w, const CDate& c) : Pet(n, l, w, c) {}
    void display(const CDate& day) override {
        int days_diff = current.differenceInDays(day);
        if (days_diff < 0) {
            cout << "error" << endl;
            return;
        }
        float new_length = length + days_diff * 0.1f;
        float new_weight = weight + days_diff * 0.2f;
        cout << fixed << setprecision(2) << name << " after " << days_diff << " day: length=" << new_length << ",weight=" << new_weight << endl;
    }
};

class Dog : public Pet {
public:
    Dog(const string& n, float l, float w, const CDate& c) : Pet(n, l, w, c) {}
    void display(const CDate& day) override {
        int days_diff = current.differenceInDays(day);
        if (days_diff < 0) {
            cout << "error" << endl;
            return;
        }
        float new_length = length + days_diff * 0.2f;
        float new_weight = weight + days_diff * 0.1f;
        cout << fixed << setprecision(2) << name << " after " << days_diff << " day: length=" << new_length << ",weight=" << new_weight << endl;
    }
};

int main() {
    int test_cases;
    cin >> test_cases;

    int start_year, start_month, start_day;
    cin >> start_year >> start_month >> start_day;
    CDate start_date(start_year, start_month, start_day);

    for (int i = 0; i < test_cases; ++i) {
        int type;
        string name;
        float length, weight;
        int measure_year, measure_month, measure_day;
        
        cin >> type >> name >> length >> weight >> measure_year >> measure_month >> measure_day;
        CDate measure_date(measure_year, measure_month, measure_day);

        Pet* pt = nullptr;
        if (type == 1) {
            pt = new Cat(name, length, weight, start_date);
        } else if (type == 2) {
            pt = new Dog(name, length, weight, start_date);
        }

        if (pt) {
            pt->display(measure_date);
            delete pt;
        }
    }

    return 0;
}*/
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
    int year;
    int month;
    int day;

  public:
    CDate(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d)
    {
    }
    int getyear() const
    {
        return year;
    }
    int getmonth() const
    {
        return month;
    }
    int getday() const
    {
        return day;
    }
    friend bool isLeapYear(int year);
    bool operator<(const CDate& other)
    {
        if (year != other.year)
        {
            return year < other.year;
        }
        if (month != other.month)
        {
            return month < other.month;
        }
        return day < other.day;
    }
    friend int operator-(const CDate& a, const CDate& b);
};
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int operator-(const CDate& a, const CDate& b)
{
    // const对象无法调用非const成员函数
    int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ans = 0;
    // 同年
    if (a.getyear() == b.getyear())
    {
        if (a.getmonth() == b.getmonth())
        {
            return b.getday() - a.getday();
        }
        else
        {
            ans += d[a.getmonth()] - a.getday();
            for (int i = a.getmonth() + 1; i < b.getmonth(); i++)
            {
                ans += d[i];
            }
            ans += b.getday();
        }
    }
    else
    {
        // 不同年
        ans += d[a.getmonth()] - a.getday();
        for (int i = a.getmonth() + 1; i <= 12; i++)
        {
            ans += d[i];
        }
        for (int i = a.getyear() + 1; i < b.getyear(); i++)
        {
            ans += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 1; i < b.getmonth(); i++)
        {
            ans += d[i];
        }
        ans += b.getday();
    }
    return ans;
}
class Pet
{
  protected:
    string name;   // 姓名
    float length;  // 身长
    float weight;  // 体重
    CDate current; // 开始记录时间
  public:
    Pet(string n, float l, float w, CDate c) : name(n), length(l), weight(w), current(c)
    {
    }
    virtual void display(CDate day) = 0; // 输出目标日期时宠物的身长和体重
};
class Cat : public Pet
{
  public:
    Cat(string n, float l, float w, CDate c) : Pet(n, l, w, c)
    {
    }
    void display(CDate day)
    {
        int days = current - day;
        float newLength = length + days * 0.1;
        float newWeight = weight + days * 0.2;
        cout << fixed << setprecision(2) << name << " after " << days << " day: length=" << newLength
             << ",weight=" << newWeight << endl;
    }
};
class Dog : public Pet
{
  public:
    Dog(string n, float l, float w, CDate c) : Pet(n, l, w, c)
    /*由于这些变量在父类 Pet 中被声明为 protected，所以你不能在派生类的初始化列表中直接初始化它们。
    你需要在 Cat 类的构造函数中调用 Pet 类的构造函数来初始化这些变量。*/
    {
    }
    void display(CDate day)
    {
        int days = current - day;
        float newLength = length + days * 0.2;
        float newWeight = weight + days * 0.1;
        cout << fixed << setprecision(2) << name << " after " << days << " day: length=" << newLength
             << ",weight=" << newWeight << endl;
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    int cYear, cMonth, cDay;
    cin >> cYear >> cMonth >> cDay;
    CDate c(cYear, cMonth, cDay);
    Pet* p;
    while (t--)
    {
        int type;
        cin >> type;
        string name;
        float length, weight;
        int year, month, day;
        cin >> name >> length >> weight >> year >> month >> day;
        CDate nc(year, month, day);
        if (!(c < nc))
        {
            cout << "error" << endl;
            continue;
        }
        if (type == 1)
        {
            p = new Cat(name, length, weight, c);
        }
        else
        {
            p = new Dog(name, length, weight, c);
        }
        p->display(nc);
    }
    return 0;
}