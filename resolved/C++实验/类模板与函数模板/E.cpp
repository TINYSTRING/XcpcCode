#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int long long
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
template<class T>
class Clist
{
private:
    T* a=new T[120];
    int size;
public:
Clist(T *b,int n)
{
    f(i,1,n)
    {
        a[i]= b[i];
    }
    size=n;
}
void insert(int pos,T value)
{
    T *b=new T[120];
    f(i,1,size)
    {
        b[i]=a[i];
    }
    a[pos]=value;
    size++;
    f(i,pos+1,size)
    {
        a[i]=b[i-1];
    }
}
void erase(int pos)
{
    T *b=new T[120];
    int len=0;
    f(i,1,size)
    {
        if(i==pos)
        {
            continue;
        }
        b[++len]=a[i];
    }
    if(size!=len+1)
    {
        cout<<"fuck!!!!"<<endl;
    }
    size--;
    f(i,1,size)
    {
        a[i]=b[i];
    }
}
void print()
{
    f(i,1,size)
    {
        if(i==1)
        {
            cout<<a[i];
            continue;
        }
        cout<<" "<<a[i]; 
    }
}
};
signed main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin>>n;
    int *a=new int[n+2];
    f(i,1,n)
    {
        cin>>a[i];
    }
    Clist<int> clist(a,n);
    int pos,value;
    cin>>pos>>value;
    clist.insert(pos+1,value);
    cin>>pos;
    clist.erase(pos+1);
    clist.print();
    cout<<endl;
    cin>>n;
    float *b=new float[n+2];
    f(i,1,n)
    {
        cin>>b[i];
    }
    float value1;
    Clist<float>flist(b,n);
    cin>>pos>>value1;
    flist.insert(pos+1,value1);
    cin>>pos;
    flist.erase(pos+1);
    flist.print();


    return 0;
}