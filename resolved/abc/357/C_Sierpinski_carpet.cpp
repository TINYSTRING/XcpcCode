#include <iostream>
#include <vector>
#include <string>

// 生成第K级地毯的函数
std::vector<std::string> generate_carpet(int K) {
    if (K == 0) {
        return std::vector<std::string>{"#"};
    }

    // 生成较小的第(K-1)级地毯
    std::vector<std::string> smaller_carpet = generate_carpet(K - 1);
    int size = smaller_carpet.size();
    std::vector<std::string> new_carpet(size * 3);

    // 填充新的地毯
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == 1) { // 中间的行
                new_carpet[i * size + j] = smaller_carpet[j] + std::string(size, '.') + smaller_carpet[j];
            } else { // 顶部和底部的行
                new_carpet[i * size + j] = smaller_carpet[j] + smaller_carpet[j] + smaller_carpet[j];
            }
        }
    }

    return new_carpet;
}

// 打印地毯的函数
void print_carpet(const std::vector<std::string>& carpet) {
    for (const std::string& row : carpet) {
        std::cout << row << std::endl;
    }
}

int main() {
    int N;
    std::cin >> N;

    // 生成第N级地毯
    std::vector<std::string> carpet = generate_carpet(N);

    // 打印地毯
    print_carpet(carpet);

    return 0;
}
