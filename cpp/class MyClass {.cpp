#include<iostream>
class MyClass {
private:
    int privateVar;

public:
    void setPrivateVar(int value) {
        privateVar = value;  // 可以在类内部访问
    }

    int getPrivateVar() {
        return privateVar;   // 可以在类内部访问
    }
};

int main() {
    MyClass obj;
    // obj.privateVar = 10; // 错误，无法直接访问 private 成员
    obj.setPrivateVar(10);  // 通过 public 方法间接访问
    std::cout << obj.getPrivateVar() << std::endl;  // 通过 public 方法间接访问
    return 0;
}

