#include <vector>
#include <iostream>

// Ex6.54
// 编写函数的声明，令其接受两个int形参并且返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。
int F(int , int);
using FP = decltype(F)*;
std::vector<FP> kVec;

// Ex6.55
// 编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。
int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

// Ex6.66
// 调用上述vector对象中的每个元素并输出其结果。
void Print() {
    for(const auto& f : kVec) {
        std::cout << (*f)(6, 3) << std::endl;
    }
}

int main() {
    kVec.emplace_back(Add);
    kVec.emplace_back(Sub);
    kVec.emplace_back(Mul);
    kVec.emplace_back(Div);

    Print();

    return 0;
}