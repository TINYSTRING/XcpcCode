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
class Member
{
    protected:
        int number;
        string name;
        int score;
    public:
        Member(int n,string na,int s):number(n),name(na),score(s){}
        virtual void print()
        {
            cout<<"普通会员"<<number<<"--"<<name<<"--"<<score<<endl;
        }
        virtual void add(int s)
        {
            score+=s;
        }
        virtual int exchange(int s)
        {
            score-=s;
            return s/100;
        }
};
class VIP:public Member
{
    private:
        int a,b;
    public:
        VIP(int n,string na,int s,int aa,int bb):Member(n,na,s),a(aa),b(bb){}
        void print()
        {
            cout<<"贵宾会员"<<number<<"--"<<name<<"--"<<score<<endl;
        }
        void add(int s)
        {
            score+=s*a;
        }
        int exchange(int s)
        {
            score-=(s/b)*b;
            return s/100;
        }

};
signed main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)
    {
        Member* pm;
        int n,s;
        string na;
        cin>>n>>na>>s;
        pm=new Member(n,na,s);
        int a,b;
        cin>>a>>b;
        pm->add(a);
        pm->exchange(b);
        pm->print();
        cin>>n>>na>>s>>a>>b;
        pm=new VIP(n,na,s,a,b);
        cin>>a>>b;
        pm->add(a);
        pm->exchange(b);
        pm->print();
    }

    return 0;
}