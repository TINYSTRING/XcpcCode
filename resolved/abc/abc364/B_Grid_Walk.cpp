#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    int S_i, S_j;
    cin >> S_i >> S_j;
    S_i--; // 将1-based索引转换为0-based索引
    S_j--; // 将1-based索引转换为0-based索引

    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> grid[i];
    }

    string X;
    cin >> X;

    int current_i = S_i;
    int current_j = S_j;

    for (char move : X)
    {
        if (move == 'L' && current_j > 0 && grid[current_i][current_j - 1] == '.')
        {
            current_j--;
        }
        else if (move == 'R' && current_j < W - 1 && grid[current_i][current_j + 1] == '.')
        {
            current_j++;
        }
        else if (move == 'U' && current_i > 0 && grid[current_i - 1][current_j] == '.')
        {
            current_i--;
        }
        else if (move == 'D' && current_i < H - 1 && grid[current_i + 1][current_j] == '.')
        {
            current_i++;
        }
    }

    cout << current_i + 1 << " " << current_j + 1 << endl; // 将0-based索引转换为1-based索引
    return 0;
}