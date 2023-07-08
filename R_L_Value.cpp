#include <iostream>

class A {
    int something;
public:
    A(int some) : something(some) {}

    // For lvalue reference
    void print(A& obj) const {
        std::cout << "Print lvalue reference: " << obj.something << std::endl;
    }

    // For rvalue reference
    void print(A&& obj) const {
        std::cout << "Print rvalue reference: " << obj.something << std::endl;
    }

    // For const lvalue reference and const rvalue reference
    void print(const A& obj) const {
        std::cout << "Print const lvalue or const rvalue reference: " << obj.something << std::endl;
    }
};

int main() {
    A obj(10);

    obj.print(obj);                                    // Lvalue
    obj.print(static_cast<A&>(obj));                    // Lvalue reference
    obj.print(static_cast<const A&>(obj));              // Const lvalue reference
    obj.print(std::move(obj));                          // Rvalue reference
    obj.print(static_cast<const A&&>(A(15)));           // Const rvalue reference

    return 0;
}