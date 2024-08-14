#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#define f(i, s, e) for (int i = s; i <= e; i++)
#define ff(i, s, e) for (int i = s; i >= e; i--)
using namespace std;
// set<int>::iterator it;
int N, K;
int main(void)
{
    int l, r;
    while (cin >> N >> K)
    {
        vector<int> len(N);
        int max_len = 0;
        f(i, 0, N - 1)
        {
            double t;
            cin >> t;
            len[i] = t * 100.0;
            max_len = max(max_len, len[i]);
        }
        l = 1, r = max_len;
        int ans = 0; // 答案
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cnt = 0; // 计数器，是否大于等于K
            f(i, 0, N - 1)
            {
                cnt += len[i] / mid;
            }
            if (cnt >= K)
            {
                l = mid + 1;
                ans = max(ans, mid); // 找最大值
            }
            else
                r = mid - 1;
        }
        cout << fixed << setprecision(2) << ans / 100.0 << endl;
    }

    return 0;
}