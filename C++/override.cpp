
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    
    // 获取实部和虚部
    double getReal() const { return real; }
    double getImag() const { return imag; }
    
    // 设置实部和虚部
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }
    
    // 重载加法运算符 (成员函数形式)
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    // 重载减法运算符 (成员函数形式)
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    
    // 重载乘法运算符 (成员函数形式)
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                      real * other.imag + imag * other.real);
    }
    
    // 重载除法运算符 (成员函数形式)
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                      (imag * other.real - real * other.imag) / denominator);
    }
    
    // 重载复合加法赋值运算符 (成员函数形式)
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }
    
    // 重载相等运算符 (成员函数形式)
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }
    
    // 重载不相等运算符 (成员函数形式)
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
    
    // 重载一元负号运算符 (成员函数形式)
    Complex operator-() const {
        return Complex(-real, -imag);
    }
    
    // 重载前缀递增运算符 (成员函数形式)
    Complex& operator++() {
        ++real;
        return *this;
    }
    
    // 重载后缀递增运算符 (成员函数形式)
    Complex operator++(int) {
        Complex temp = *this;
        ++real;
        return temp;
    }
    
    // 重载类型转换运算符 (转换为double，表示模长)
    operator double() const {
        return sqrt(real * real + imag * imag);
    }
    
    // 重载函数调用运算符 (成员函数形式)
    Complex operator()(double r, double i) {
        real = r;
        imag = i;
        return *this;
    }
    
    // 友元函数声明，用于重载输出运算符
    friend ostream& operator<<(ostream& os, const Complex& c);
    
    // 友元函数声明，用于重载输入运算符
    friend istream& operator>>(istream& is, Complex& c);
};

// 重载输出运算符 (全局函数形式)
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i";
    } else {
        os << " - " << -c.imag << "i";
    }
    return os;
}

// 重载输入运算符 (全局函数形式)
istream& operator>>(istream& is, Complex& c) {
    cout << "请输入实部: ";
    is >> c.real;
    cout << "请输入虚部: ";
    is >> c.imag;
    return is;
}

// 重载加法运算符 (全局函数形式，用于处理 double + Complex 的情况)
Complex operator+(double d, const Complex& c) {
    return Complex(d + c.getReal(), c.getImag());
}

int main() {
    cout << "=== 运算符重载示例 ===" << endl;
    
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    
    // 使用重载的运算符
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    Complex sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl;
    
    Complex diff = c1 - c2;
    cout << "c1 - c2 = " << diff << endl;
    
    Complex product = c1 * c2;
    cout << "c1 * c2 = " << product << endl;
    
    Complex quotient = c1 / c2;
    cout << "c1 / c2 = " << quotient << endl;
    
    c1 += c2;
    cout << "c1 += c2 后，c1 = " << c1 << endl;
    
    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;
    
    Complex neg = -c1;
    cout << "-c1 = " << neg << endl;
    
    cout << "c1 的模长: " << (double)c1 << endl;
    
    // 测试函数调用运算符
    c1(5.0, 6.0);
    cout << "调用 c1(5.0, 6.0) 后，c1 = " << c1 << endl;
    
    // 测试全局函数重载的运算符
    Complex c3 = 2.5 + c1;
    cout << "2.5 + c1 = " << c3 << endl;
    
    // 测试输入运算符
    Complex c4;
    cin >> c4;
    cout << "你输入的复数是: " << c4 << endl;
    
    return 0;
} 