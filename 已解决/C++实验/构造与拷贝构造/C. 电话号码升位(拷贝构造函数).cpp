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
class CtelNumber
{
    private:
        char *telNumber;
    public:
        CtelNumber()
        {
            telNumber = new char[11];
            strcpy(telNumber,"00000000000");
        }
        CtelNumber(char *tel)
        {
            telNumber = new char[11];
            strcpy(telNumber,tel);
        }
        CtelNumber(const CtelNumber &obj)
        {
            telNumber = new char[11];
            if(obj.telNumber[0]<='4'&&obj.telNumber[0]>='2'&&strlen(obj.telNumber)==7)
            {
                strcpy(telNumber, "8");
                strcat(telNumber, obj.telNumber);
                cout<<telNumber<<endl;
            }else if(obj.telNumber[0]<='8'&&obj.telNumber[0]>='5'&&strlen(obj.telNumber)==7)
            {
                strcpy(telNumber, "2");
                strcat(telNumber, obj.telNumber);
                cout<<telNumber<<endl;
            }else 
            {
                cout<<"Illegal phone number"<<endl;
            }
        }
        ~CtelNumber()
        {
            delete [] telNumber;
        }
};
bool check(char *tel)
{
    f(i,0,strlen(tel)-1)
    {
        if(tel[i]<'0'||tel[i]>'9')
        {
            return true;
        }
    }
    return false;
}
signed main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        char tel[11];
        cin>>tel;
        if(check(tel))
        {
            cout<<"Illegal phone number"<<endl;
            continue;
        }
        CtelNumber obj1(tel);
        CtelNumber obj2(obj1);
    }

    return 0;
}