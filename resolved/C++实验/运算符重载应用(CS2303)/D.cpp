#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int long long
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
class CXGraph
{
  private:
    int n; // 行数
  public:
    CXGraph(int n) : n(n)
    {
    }
    CXGraph operator++(int)
    {
        CXGraph temp = *this;
        if(n==21)
        {
            return temp;
        }
        n += 2;
        return temp;
    }
    CXGraph operator--(int)
    {
        CXGraph temp = *this;
        if(n==1)
        {
            return temp;
        }
        n -= 2;
        return temp;
    }
    CXGraph operator++()
    {
        if(n==21)
        {
            return *this;
        }
        n += 2;
        return *this;
    }
    CXGraph operator--()
    {
        if(n==1)
        {
            return *this;
        }
        n -= 2;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const CXGraph& xGraph);
};
ostream& operator<<(ostream& os, const CXGraph& xGraph)
{
    for(int i=xGraph.n;i>=1;i-=2)
    {
        //补齐空格
        f(j,1,(xGraph.n-i)/2)
        {
            os << " ";
        }
        f(j,1,i)
        {
            os << "X";
        }
        os << endl;
    }
    for(int i=3;i<=xGraph.n;i+=2)
    {
        //补齐空格
        f(j,1,(xGraph.n-i)/2)
        {
            os << " ";
        }
        f(j,1,i)
        {
            os << "X";
        }
        os << endl;
    }
    return os;
}

int main()
{
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
        {
            cout << xGraph++ << endl;
        }
        else if (command == "++show")
        {
            cout << ++xGraph << endl;
        }
        else if (command == "show--")
        {
            cout << xGraph-- << endl;
        }
        else if (command == "--show")
        {
            cout << --xGraph << endl;
        }
        else if (command == "show")
        {
            cout << xGraph << endl;
        }
    }
    return 0;
}