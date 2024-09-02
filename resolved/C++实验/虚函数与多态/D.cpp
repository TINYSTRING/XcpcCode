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
class Animal
{
  public:
    virtual void speak() = 0;
};
class Tiger : public Animal
{
  public:
    string n;
    int age;
    Tiger(string n, int age) : n(n), age(age)
    {
    }
    void speak()
    {
        cout << "Hello,I am " << n << ",";
        cout << "AOOO." << endl;
    }
};
class Dog : public Animal
{

  public:
    string n;
    int age;
    Dog(string n, int age) : n(n), age(age)
    {
    }
    void speak()
    {
        cout << "Hello,I am " << n << ",";
        cout << "WangWang." << endl;
    }
};
class Duck : public Animal
{
  public:
    string n;
    int age;
    Duck(string n, int age) : n(n), age(age)
    {
    }
    void speak()
    {
        cout << "Hello,I am " << n << ",";
        cout << "GAGA." << endl;
    }
};
class Pig : public Animal
{
  public:
    string n;
    int age;
    Pig(string n, int age) : n(n), age(age)
    {
    } // 构造函数
    void speak()
    {
        cout << "Hello,I am " << n << ",";
        cout << "HENGHENG." << endl;
    }
};
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Animal* p;
        string s;
        cin >> s;
        string n;
        int age;
        cin>>n>>age;
        if (s == "Tiger")
        {

            p = new Tiger(n, age);
            p->speak();
        }
        else if (s == "Dog")
        {

            p = new Dog(n, age);
            p->speak();
        }
        else if (s == "Duck")
        {

            p = new Duck(n, age);
            p->speak();
        }
        else if (s == "Pig")
        {

            p = new Pig(n, age);
            p->speak();
        }
        else
        {
            cout << "There is no " << s << " in our Zoo." << endl;
        }
    }

    return 0;
}