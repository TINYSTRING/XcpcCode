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
//set<int>::iterator it;\
//栈类
class CStack
{
  private:
    int* arr;
    int top;
    int size;

  public:
    CStack();
    CStack(int s);
    int get(int index);
    void push(int n);
    int isEmpty();
    int isFull();
    int pop();
    void clear();
    ~CStack();
};
CStack::CStack()
{
    top = -1;
    size = 10;
    arr = new int[size];
    cout << "Constructor." << endl;
}
CStack::CStack(int s)
{
    top = -1;
    size = s;
    arr = new int[size];
    cout << "Constructor." << endl;
}
int CStack::get(int index)
{
    if (index > top)
    {
        cout << "Index out of bound" << endl;
        return -1;
    }
    return arr[index];
}
void CStack::push(int n)
{
    if (isFull())
    {
        cout << "Stack is full" << endl;
        return;
    }
    arr[++top] = n;
}
int CStack::isEmpty()
{
    return top == -1;
}
int CStack::isFull()
{
    return top == size - 1;
}
int CStack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return arr[top--];
}
CStack::~CStack()
{
    delete[] arr;
    cout << "Destructor." << endl;
}
void solve()
{
    int n;
    cin >> n;
    CStack s(n);
    f(i, 1, n)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    ff(i, n - 1, 1)
    {
        cout << s.get(i) << " ";
    }
    cout << s.get(0) << endl;
    return;
}
signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}