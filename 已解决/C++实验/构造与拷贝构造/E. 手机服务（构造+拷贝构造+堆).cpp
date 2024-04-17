#include <bits/stdc++.h>
#include <new>
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
/*设计一个类来实现手机的功能。它包含私有属性：号码类型、号码、号码状态、停机日期；包含方法：构造、拷贝构造、打印、停机。
1、号码类型表示用户类别，只用单个字母，A表示机构，B表示企业、C表示个人
2、号码是11位整数，用一个字符串表示
3、号码状态用一个数字表示，1、2、3分别表示在用、未用、停用
4、停机日期是一个日期对象指针，在初始化时该成员指向空，该日期类包含私有属性年月日，以及构造函数和打印函数等
----------------------------------------

5、构造函数的作用就是接受外来参数，并设置各个属性值,并输出提示信息，看示例输出
6、拷贝构造的作用是复制已有对象的信息，并输出提示信息，看示例输出。
      想一下停机日期该如何复制，没有停机如何复制？？已经停机又如何复制？？

7、打印功能是把对象的所有属性都输出，输出格式看示例
8、停机功能是停用当前号码，参数是停机日期，无返回值，操作是把状态改成停用，并停机日期指针创建为动态对象，并根据参数来设置停机日期，最后输出提示信息，看示例输出
-------------------------------------------

要求：在主函数中实现号码备份的功能，对已有的虚拟手机号的所有信息进行复制，并将号码类型改成D表示备份；将手机号码末尾加字母X
 */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class phone
{
  private:
    char type;
    string num;
    int state;
  public:
    phone(){};
    phone(phone& zhuji)
    {
        type = zhuji.type;
        num = zhuji.num;
        state = zhuji.state;
        cout << "Construct a copy of phone " << num << endl;
        cout << "类型=备份||";
        cout << "号码=" << num << "X";
        switch (state)
        {
        case 1:
            cout << "||State=在用" << endl;
            break;
        case 2:
            cout << "||State=未用" << endl;
            break;
        case 3:
            cout << "||State=停用" << endl;
            break;
        }
    }
    void setphone(char type1, string num1, int state1)
    {
        type = type1;
        num = num1;
        state = state1;
        cout << "Construct a new phone " << num << endl;
    }
    void printphone()
    {
        switch (type)
        {
        case 'A':
            cout << "类型=机构||";
            break;
        case 'B':
            cout << "类型=企业||";
            break;
        case 'C':
            cout << "类型=个人||";
            break;
        }
        cout << "号码=" << num;
        switch (state)
        {
        case 1:
            cout << "||State=在用" << endl;
            break;
        case 2:
            cout << "||State=未用" << endl;
            break;
        case 3:
            cout << "||State=停用" << endl;
            break;
        }
    }
    void stop(int y, int m, int d)
    {
        cout << "Stop the phone " << num << endl;
        switch (type)
        {
        case 'A':
            cout << "类型=机构||";
            break;
        case 'B':
            cout << "类型=企业||";
            break;
        case 'C':
            cout << "类型=个人||";
            break;
        }
        cout << "号码=" << num << "||State=停用||停机日期=" << y << "." << m << "." << d << endl;
        cout << "----" << endl;
    }
};

signed main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    char type;
    string num;
    int state, t, y, m, d;
    phone p1;
    cin >> t;
    while (t--)
    {
        cin >> type >> num >> state >> y >> m >> d;
        p1.setphone(type, num, state);
        p1.printphone();
        phone p2(p1);
        p2.stop(y, m, d);
    }
    return 0;
}