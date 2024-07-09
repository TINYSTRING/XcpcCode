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
template<class T>
bool check(T a[])
{
    T b[10];
    f(i,1,6)
    {
        b[i] = a[i];
    }
    sort(b+1,b+7);
    f(i,1,6)
    {
        if(b[i]!=a[i])
        {
            return false;
        }
    }
    return true;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    while (cin >> s)
    {
        bool flag = false;
        if (s == "c")
        {
            char* a = new char[10];
            f(i,1,6)
            {
                cin>>a[i];
            }
            flag = check(a);
        }
        else if (s == "i")
        {
            int* a = new int[10];
            f(i,1,6)
            {
                cin>>a[i];
            }
            flag = check(a);
        }
        else
        {
            float* a = new float[10];
            f(i,1,6)
            { 
                cin>>a[i];
            }
            flag = check(a);
        }
        if(flag)
        {
            cout<<"Valid"<<endl;
        }
        else
        {
            cout<<"Invalid"<<endl;
        }
    }
    return 0;
}