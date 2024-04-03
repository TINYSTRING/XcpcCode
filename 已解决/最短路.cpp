// #include <bits/stdc++.h>
// #define ll long long
// #define int long long
// #define pii pair<int, int>
// #define pb push_back
// #define endl '\n'
// #define gcd __gcd
// #define f(i, s, e) for (int i = s; i <= e; i++)
// #define ff(i, s, e) for (int i = s; i >= e; i--)
// #define setbits(x) __builtin_popcount(x)
// #define zrobits(x) __builtin_ctzll(x)
// #define mod 100000007
// #define maxn (ll)(2e5 + 5000)
// #define INF 0x3f3f3f3f
// using namespace std;
// // set<int>::iterator it;
// pii edge;
// vector<pii> g[maxn];//存储要到的顶点和距离
// priority_queue<pii, vector<pii>, greater<pii>> q;
// int dist[maxn];
// int pre[maxn];
// void dijstra(int s)
// {
//     dist[s] = 0;
//     q.push({0, s});
//     while (!q.empty())
//     {
//         int u = q.top().second;
//         int du = q.top().first;
//         q.pop();
//         if (du > dist[u])
//             continue;
//         for (auto x : g[u])
//         {
//             int v = x.first;
//             int w = x.second;
//             if (dist[v] > dist[u] + w)
//             {
//                 pre[v] = u;// 存储父节点，以便打印具体路径
//                 dist[v] = dist[u] + w;
//                 q.push({dist[v], v});
//             }
//         }
        
//     }
//     return ;
// }
// signed main(void)
// {
//     ios::sync_with_stdio(false), cin.tie(nullptr);
//     memset(dist, 0x3f, sizeof(dist));//初始化
//     int n, m,s;
//     cin >> n >> m>>s;
//     f(i, 0, m - 1)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//     }
//     dijstra(s);
//     f(i,1,n)
//     {
//         cout<<dist[i]<<" ";
//     }

//     return 0;
// }
// #include <bits/stdc++.h>
// #define ll long long
// #define int long long
// #define pii pair<int, int>
// #define pb push_back
// #define gcd __gcd
// #define lcm(a, b) (a * b) / gcd(a, b)
// #define all(a) a.begin(), a.end()
// #define mem(a, x) memset(a, x, sizeof(a))
// #define f(i, s, e) for (int i = s; i <= e; i++)
// #define ff(i, s, e) for (int i = s; i >= e; i--)
// #define setbits(x) __builtin_popcount(x)
// #define zrobits(x) __builtin_ctzll(x)
// #define mod 100000007
// #define maxn (ll)(2e5 + 5000)
// #define INF 0x3f3f3f3f
// using namespace std;
// // set<int>::iterator it;
// /*已知一群学生的考试试卷，要求对试卷内容进行对比，查找是否有抄袭。

// 每张试卷包含：学号（整数类型）、题目1答案（字符串类型）、题目2答案（字符串类型）、题目3答案（字符串类型）

// 要求：使用结构体来存储试卷的信息。定义一个函数，返回值为一个整数，参数是两个结构体指针，函数操作是比较两张试卷的每道题目的答案，如果相同题号的答案相似度超过90%，那么就认为有抄袭，函数返回抄袭题号，否则返回0。相似度是指在同一题目中，两个答案的逐个位置上的字符两两比较，相同的数量大于等于任一个答案的长度的90%，就认为抄袭。
// */
// struct student
// {
//     int id;
//     string ans1;
//     string ans2;
//     string ans3;
// };
// student a[maxn];
// map<string, int> mp;
// signed main(void)
// {
//     ios::sync_with_stdio(false), cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> a->id;
//         cin >> a->ans1 >> a->ans2 >> a->ans3;
//         if (mp[a->ans1])
//         {
//             cout << mp[a->ans1] << " " << a->id << " " << 1 << endl;
//         }
//         else if (mp[a->ans2])
//         {
//             cout << mp[a->ans2] << " " << a->id << " " << 2 << endl;
//         }
//         else if (mp[a->ans3])
//         {
//             cout << mp[a->ans3] << " " << a->id << " " << 3 << endl;
//         }
//         else
//         {
//             mp[a->ans1] = a->id;
//             mp[a->ans2] = a->id;
//             mp[a->ans3] = a->id;
//         }
//     }

//     return 0;
// }