# 程序设计Ⅱ - 周7 理论题

## 题目来源

程设Ⅱ - 周7 - 理论题

## 题目描述

第七周理论题，动态对象与指针，=delete和=default，对象成员初始化，对象的内存布局，拷贝构造函数，深入const

---

### 第1题 - 单选题

关于C++中对象的存储与释放，下列说法正确的是

- **A.** 用new创建的对象通常位于栈区，离开作用域后会自动释放
- **B.** 局部对象通常位于堆区，必须使用delete才能释放
- **C.** 用new创建的对象需要显式释放，否则可能造成内存泄漏
- **D.** 对指针执行delete后，指针会自动变为 nullptr

> **标准答案：C**

---

### 第2题 - 单选题

有关下列代码说法正确的是
#include <iostream>
using namespace std;
int main() {
int* p = new int(5);
int* q = p;
delete p;
return 0;
}

- **A.** q会自动变为nullptr
- **B.** 此时q仍然指向原地址值，但该地址已经失效
- **C.** 此时仍可通过*q安全访问原来的值5
- **D.** 此时再次执行delete q一定是安全的

> **标准答案：B**

---

### 第3题 - 单选题

关于构造函数的成员初始化列表，下列说法正确的是

- **A.** 成员初始化列表中的初始化发生在构造函数体执行之后
- **B.** 在构造函数体内对成员赋值，与成员初始化列表初始化完全等价
- **C.** 成员初始化列表中的初始化发生在进入构造函数体之前
- **D.** 所有成员都必须在构造函数体内赋值，不能在初始化列表中处理

> **标准答案：C**

---

### 第4题 - 单选题

设有如下定义：
int a = 10, b = 20;
const int* p1 = &a;
int* const p2 = &a;
下列说法正确的是

- **A.** p1和p2都不能修改所指向的值
- **B.** p1不能通过它修改所指向的值，但可以改为指向别处；p2 可以通过它修改所指向的值，但不能改为指向别处
- **C.** p1不能改为指向别处，但可以通过它修改所指向的值；p2正好相反
- **D.** p1和p2都既不能修改指向，也不能修改所指向的值

> **标准答案：B**

---

### 第5题 - 单选题

关于普通类对象在内存中的组成，下列说法正确的是

- **A.** 对象中包含该类所有成员函数的代码副本
- **B.** 类的静态数据成员属于每个对象各自独立拥有的一份数据
- **C.** 普通对象通常包含其非静态数据成员所需的存储空间
- **D.** 不同对象之间会共享各自的非静态数据成员

> **标准答案：C**

---

### 第6题 - 单选题

下列代码的输出结果是
#include <iostream>
using namespace std;
class Test {
public:
Test() { cout << "C "; }
~Test() { cout << "D "; }
};
int main() {
Test t1;
Test* p = new Test;
delete p;
return 0;
}

- **A.** C D C D
- **B.** C C D D
- **C.** C C D
- **D.** C D D C

> **标准答案：B**

---

### 第7题 - 单选题

关于拷贝构造函数，下列说法正确的是

- **A.** 对象已经存在后，再执行赋值语句，一定会调用拷贝构造函数
- **B.** 用一个已有对象去初始化同类新对象时，通常会调用拷贝构造函数
- **C.** 拷贝构造函数的参数必须按值传递
- **D.** 拷贝构造函数只能手动调用，编译器不会自动调用

> **标准答案：B**

---

### 第8题 - 单选题

有关下列代码的说法正确的是：
#include <iostream>
using namespace std;
class A {
private:
const int x;
public:
A() {
x = 10;
}
};

- **A.** 代码可以正常编译，因为const成员可以先定义再在构造函数体内赋值
- **B.** 代码不能通过编译，因为const数据成员必须在成员初始化列表中初始化
- **C.** 代码不能通过编译，因为类中不能定义const数据成员
- **D.** 代码可以正常编译，但运行时会报error

> **标准答案：B**

---

### 第9题 - 单选题

有关下列代码，哪一项说法正确
#include <iostream>
using namespace std;
class A {
private:
int x;
public:
A(int v) : x(v) {}
void f() { cout << x << endl; }
void g() const { cout << x << endl; }
};
int main() {
const A a(10);
a.g();
a.f();
return 0;
}

- **A.** 代码可以正常编译并输出两次10
- **B.** 代码不能通过编译，因为const对象不能调用任何成员函数
- **C.** 代码不能通过编译，因为const对象不能调用非const成员函数f()
- **D.** 代码不能通过编译，因为const成员函数g()不能访问数据成员 x

> **标准答案：C**

---

### 第10题 - 单选题

下面程序的输出结果是
#include <iostream>
using namespace std;
class Counter {
private:
static int cnt;
public:
Counter() { cnt++; }
void show() const { cout << cnt << " "; }
};
int Counter::cnt = 0;
int main() {
Counter a;
Counter b;
a.show();
b.show();
return 0;
}

- **A.** 1 1
- **B.** 1 2
- **C.** 2 2
- **D.** 编译错误

> **标准答案：C**

---

> 共 10 题 | 来源：Matrix 程序设计Ⅱ