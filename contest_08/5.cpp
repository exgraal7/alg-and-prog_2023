#include <iostream>

// Начало вставленного кода
class IntSharedPointer {
private:
    int *ptr;
    int *ref_count;

public:
    IntSharedPointer(int* value);
    
    ~IntSharedPointer();

    IntSharedPointer(const IntSharedPointer& other);

    int& operator*();

    IntSharedPointer& operator=(IntSharedPointer other);
};

IntSharedPointer::IntSharedPointer(int* value) : ptr(value), ref_count(new int(1)) {}

IntSharedPointer::~IntSharedPointer() {
    (*ref_count)--;
    if (*ref_count == 0) {
        delete ptr;
        delete ref_count;
    }
}

IntSharedPointer::IntSharedPointer(const IntSharedPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
    (*ref_count)++;
}

int& IntSharedPointer::operator*() {
    return *ptr;
}

IntSharedPointer& IntSharedPointer::operator=(IntSharedPointer other) {
    std::swap(ptr, other.ptr);
    std::swap(ref_count, other.ref_count);
    return *this;
}
// Конец вставленного кода

void print(IntSharedPointer p){
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p){
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main(){
    IntSharedPointer p(new int);
    std::cin >> *p;
    p = p;
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);
    
    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);
    
    p = p2;
    try{
        print_with_exception(p);
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}
