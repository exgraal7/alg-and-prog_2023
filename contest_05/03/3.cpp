#include <iostream>
#include <string>
#include <sstream>

class Complex {
    double real, imag;
public:
    Complex(const std::string& num) {
        std::stringstream ss(num);
        char op;
        ss >> real;
        ss >> op;
        ss >> imag;
        if(op == '-') imag = -imag;
    }
    
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }
    
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }
    
    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    
    Complex operator/(const Complex& c) const {
        double denom = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denom, (imag * c.real - real * c.imag) / denom);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? '+' : '-') << std::abs(c.imag) << 'j';
        return os;
    }
    
private:
    Complex(double real, double imag) : real(real), imag(imag) {}
};
int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2(num);
    
    std::cout << c1+c2 << '\n' << c1-c2 << '\n'
              << c1*c2 << '\n' << c1/c2 << std::endl;
}
