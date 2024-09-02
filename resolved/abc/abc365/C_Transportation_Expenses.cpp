#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#define int long long
using namespace std;

int maxSubsidyLimit(int N, int M, vector<int>& A)
{
    int left = 0;
    int right = *max_element(A.begin(), A.end());

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        long long total_subsidy = 0;

        for (int i = 0; i < N; ++i)
        {
            total_subsidy += min(mid, A[i]);
        }

        if (total_subsidy <= M)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (accumulate(A.begin(), A.end(), 0LL) <= M)
    {
        return -1; // 表示无限大
    }
    else
    {
        return right;
    }
}

signed main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int result = maxSubsidyLimit(N, M, A);
    if (result == -1)
    {
        cout << "infinite" << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}