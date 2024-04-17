#include <iostream>
#include <string>
class Complex
{
  private:
    double real; // 实部
    double imag; // 虚部
  public:
    Complex() : real(0), imag(0)
    {
    }
    Complex(double r, double i) : real(r), imag(i)
    {
    }
    // 友元函数，复数c1 + c2(二参数对象相加)
    friend Complex addCom(const Complex& c1, const Complex& c2);
    // 友元函数，输出类对象c的有关数据(c为参数对象)
    friend void outCom(const Complex& c);
    // 友元函数，复数c1 - c2(二参数对象相减)
    friend Complex minusCom(const Complex& c1, const Complex& c2);
};

Complex addCom(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

void outCom(const Complex& c)
{
    std::cout << "(" << c.real << "," << c.imag << ")" << std::endl;
}

Complex minusCom(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

int main()
{
    double real, imag;
    std::cin >> real >> imag;
    Complex c1(real, imag);
    int operations;
    std::cin >> operations;
    for (int i = 0; i < operations; i++)
    {
        std::string op;
        std::cin >> op >> real >> imag;
        Complex c2(real, imag);

        if (op == "+")
        {
            c1 = addCom(c1, c2);
        }
        else if (op == "-")
        {
            c1 = minusCom(c1, c2);
        }
        outCom(c1);
    }
    return 0;
}