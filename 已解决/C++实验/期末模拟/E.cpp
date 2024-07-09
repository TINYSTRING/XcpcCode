#include <iostream>
#include <cstring>
using namespace std;

class CN; // 提前声明
class EN; // 提前声明

// 抽象类
class Weight
{
protected:
    char kind[20]; // 计重类型
    int gram; // 克
public:
    Weight(const char tk[] = "no name", int tg = 0)
    {
        strcpy(kind, tk);
        gram = tg;
    }
    virtual void print(ostream& out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : public Weight
{
private:
    int jin, liang, qian, remaining_grams;
public:
    CN(int j = 0, int l = 0, int q = 0, int rg = 0, const char tk[] = "中国计重") : Weight(tk, rg), jin(j), liang(l), qian(q), remaining_grams(rg) {}

    void Convert(int tg)
    {
        gram = tg;
        jin = gram / 500;
        gram %= 500;
        liang = gram / 50;
        gram %= 50;
        qian = gram / 5;
        remaining_grams = gram % 5;
    }

    void print(ostream& out) override
    {
        out << kind << ":" << jin << "斤" << liang << "两" << qian << "钱" << remaining_grams << "克" << endl;
    }

    friend ostream& operator<<(ostream& out, CN& w)
    {
        w.print(out);
        return out;
    }

    CN& operator=(const EN& en);
};

// 英国计重
class EN : public Weight
{
private:
    int pound, ounce, dram, remaining_grams;
public:
    EN(int p = 0, int o = 0, int d = 0, int rg = 0, const char tk[] = "英国计重") : Weight(tk, rg), pound(p), ounce(o), dram(d), remaining_grams(rg) {}

    void Convert(int tg)
    {
        gram = tg;
        pound = gram / 512;
        gram %= 512;
        ounce = gram / 32;
        gram %= 32;
        dram = gram / 2;
        remaining_grams = gram % 2;
    }

    void print(ostream& out) override
    {
        out << kind << ":" << pound << "磅" << ounce << "盎司" << dram << "打兰" << remaining_grams << "克" << endl;
    }

    friend ostream& operator<<(ostream& out, EN& w)
    {
        w.print(out);
        return out;
    }

    friend CN& CN::operator=(const EN& en);
};

// 实现CN的赋值操作
CN& CN::operator=(const EN& en)
{
    int total_grams = en.pound * 512 + en.ounce * 32 + en.dram * 2 + en.remaining_grams;
    this->Convert(total_grams);
    return *this;
}

int main()
{
    int tw;
    // 创建一个中国计重类对象cn
    // 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
    CN cn(0, 0, 0, 0, "中国计重");
    cin >> tw;
    cn.Convert(tw); // 把输入的克数转成中国计重
    cout << cn;

    // 创建英国计重类对象en
    // 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
    EN en(0, 0, 0, 0, "英国计重");
    cin >> tw;
    en.Convert(tw); // 把输入的克数转成英国计重
    cout << en;
    cn = en; // 把英国计重转成中国计重
    cout << cn;
    return 0;
}
