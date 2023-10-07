#include <iostream>
#include <sstream>

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

Complex make_complex (std::string& input){
    std::stringstream ss(input);
    long double re;
    long double im;
    char c;
    ss >> re >> std::ws >> c >> std::ws >> im;
    if (c == '-'){
        im = -im;
    }
    return {re, im};
}


void print(const Complex& c){
    if (c.im > 0){
        std::cout << c.re << "+" << c.im << "j" << std::endl;
    }
	else if (std::to_string(c.im) == "-0" || c.im == 0){
        std::cout << c.re << "+" << 0 << "j" << std::endl;
    }
    else{
        std::cout << c.re << c.im << "j" << std::endl;
    }
}   

Complex sum (const Complex& c1, const Complex& c2){
    return {c1.re + c2.re, c1.im + c2.im};
}

Complex sub (const Complex& c1, const Complex& c2){
    return {c1.re - c2.re, c1.im - c2.im};
}

Complex mul (const Complex& c1, const Complex& c2){
    return {c1.re * c2.re - c1.im * c2.im, c1.re * c2.im + c1.im * c2.re};
}

Complex div (const Complex& c1, const Complex& c2){
    double comp_conj = (c2.re * c2.re + c2.im * c2.im);
    return {(c1.re * c2.re + c1.im * c2.im) / comp_conj, (c1.im * c2.re - c1.re * c2.im) / comp_conj};
}
int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
