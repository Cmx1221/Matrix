# 程序设计Ⅱ - 周4 理论题

## 题目来源

程设Ⅱ - 周4 - 理论题

## 题目描述

第四周理论题，成员访问控制、构造/析构函数、This指针、静态成员

---

### 第1题 - 单选题

一个类可以有多少个构造函数

- **A.** 1
- **B.** 2
- **C.** 3
- **D.** 任意多个

> **标准答案：D**

---

### 第2题 - 单选题

一个类可以有多少个析构函数

- **A.** 1
- **B.** 2
- **C.** 3
- **D.** 任意多个

> **标准答案：A**

---

### 第3题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class TEST {
int a, b, c;
}
int main() {
TEST test;
cout << "In main()
";
return 0;
}

- **A.** In main()
- **B.** In main()
- **C.** 编译错误
- **D.** 段错误（Segmentation Fault）

> **标准答案：C**

---

### 第4题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A{
private:
int a, b, c;
public:
A(int a, int b, int c) {
this->a = a;
this->b = b;
this->c = c;
cout << "A" << endl;
}
~A() {
cout << "~A" << endl;
}
};
int main() {
A test;
return 0;
}

- **A.** A ~A
- **B.** A
- **C.** ~A
- **D.** 编译错误

> **标准答案：D**

---

### 第5题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A{
int a, b, c;
A() {
cout << "A1" << endl;
}
A(int a, int b, int c) {
this->a = a;
this->b = b;
this->c = c;
cout << "A2" << endl;
}
~A() {
cout << "~A" << endl;
}
};
int main() {
A test;
return 0;
}

- **A.** A1 ~A
- **B.** A2 ~A
- **C.** A1 A2 ~A
- **D.** 编译错误

> **标准答案：D**

---

### 第6题 - 单选题

下列C++代码的输出是什么
#include <iostream>
#include <string>
using namespace std;
class A{
string name;
public:
A(string name) {
this->name = name;
cout << "A(" << name << ")" << endl;
}
~A() {
cout << "~A(" << name << ")" << endl;
}
};
int main() {
A a1("a1"), a2("a2");
return 0;
}

- **A.** A(a1) A(a2) ~A(a2) ~A(a1)
- **B.** A(a1) A(a2) ~A(a1) ~A(a2)
- **C.** A(a1) ~A(a1) A(a2) ~A(a2)
- **D.** 编译错误

> **标准答案：A**

---

### 第7题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A{
string name;
public:
A(string name) {
this->name = name;
cout << "A(" << name << ")" << endl;
}
~A() {
cout << "~A(" << name << ")" << endl;
}
};
int main() {
A a1("a1");
{ A a2("a2"); }
A a3("a3");
return 0;
}

- **A.** A(a1) A(a2) A(a3) ~A(a2) ~A(a3) ~A(a1)
- **B.** A(a1) A(a2) ~A(a2) A(a3) ~A(a3) ~A(a1)
- **C.** A(a1) ~A(a1) A(a2) ~A(a2) A(a3) ~A(a3)
- **D.** 编译错误

> **标准答案：B**

---

### 第8题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A{
int a = 0;
int b = 0;
int c = 0;
public:
A(int a, int b = 1, int c = 1) {
this->a = a;
this->b = b;
}
~A() {
cout << a << b << c << endl;
}
};
int main() {
A a(2,2,2);
return 0;
}

- **A.** 000
- **B.** 222
- **C.** 220
- **D.** 211

> **标准答案：C**

---

### 第9题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A{
int a = 0;
int b = 0;
int c = 0;
public:
A(int a, int b = 1, int c = 1){
this->a = a;
this->b = b;
this->c = c;
}
~A() {
cout << a << b << c << endl;
}
};
int main() {
A a(2,2,2);
return 0;
}

- **A.** 221
- **B.** 222
- **C.** 000
- **D.** 111

> **标准答案：B**

---

### 第10题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A{
int a = 0;
int b = 0;
int c = 0;
public:
A(int a, int b = 1, int c = 1) {
this->a = a;
this->b = b;
this->c = c;
}
~A() {
cout << a << b << c << endl;
}
};
int main() {
A a(3);
return 0;
}

- **A.** 111
- **B.** 331
- **C.** 313
- **D.** 311

> **标准答案：D**

---

### 第11题 - 单选题

以下关于构造函数的描述，错误的是？

- **A.** 构造函数的名称必须与类名相同
- **B.** 构造函数不能有返回值类型，包括 void
- **C.** 构造函数不能重载
- **D.** 构造函数可以有默认参数

> **标准答案：C**

---

### 第12题 - 单选题

下面关于析构函数的说法，正确的是？

- **A.** 析构函数必须由程序员手动调用
- **B.** 如果一个类没有析构函数，编译器不会生成默认析构函数
- **C.** 析构函数通常用于释放动态分配的内存
- **D.** 析构函数不能为 private

> **标准答案：C**

---

### 第13题 - 单选题

下面哪个函数不能访问 this 指针？

- **A.** 普通成员函数
- **B.** 构造函数
- **C.** 虚函数
- **D.** 静态成员函数

> **标准答案：D**

---

### 第14题 - 单选题

以下关于静态成员变量的描述，错误的是？

- **A.** 静态成员变量不能是 const
- **B.** 静态成员变量必须在类外初始化
- **C.** 静态成员变量不能在构造函数内初始化
- **D.** 静态成员变量在所有对象间共享

> **标准答案：A**

---

### 第15题 - 单选题

类的构造函数的作用是什么？

- **A.** 必要时修改数据成员
- **B.** 销毁一个对象
- **C.** 产生该对象时，初始化其数据成员
- **D.** 在外部调用私有成员函数

> **标准答案：C**

---

### 第16题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A { public: A() { cout << "A "; } ~A() { cout << "~A "; } };
void func() { static A a; }
int main() { func(); func(); return 0; }

- **A.** A ~A A ~A
- **B.** A ~A
- **C.** A A ~A ~A
- **D.** 编译错误

> **标准答案：B**

---

### 第17题 - 单选题

下列哪个选项是程序的输出：
class CDummy { public: int isitme (CDummy& param); };
int CDummy::isitme (CDummy& param) { if (&param == this) return true; else return false; }
int main () { CDummy a; CDummy *b = &a; if (b->isitme(a)) { cout << "execute"; } else { cout<<"not execute"; } return 0; }

- **A.** "execute"
- **B.** "not execute"
- **C.** 以上都不是
- **D.** 0

> **标准答案：A**

---

### 第18题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A { public: static int count; A() { count++; } ~A() { count--; } };
int A::count = 0;
int main() { A a1, a2; cout << A::count << endl; }

- **A.** 1
- **B.** 2
- **C.** 0
- **D.** 编译错误

> **标准答案：B**

---

### 第19题 - 单选题

下列C++代码的输出是什么
#include <iostream>
using namespace std;
class A {
public: int x;
A(int val){ x=val; }
A& setX(int x) { this->x = x * 2; return *this; }
void print() const { cout << "x = " << this->x << endl; }
};
int main() { A obj1(5); A obj2(10); obj1.setX(obj2.x).setX(3); obj1.print(); obj2.print(); return 0; }

- **A.** x = 6 x = 10
- **B.** x = 10 x = 10
- **C.** x = 6 x = 6
- **D.** x = 3 x = 10

> **标准答案：A**

---

### 第20题 - 单选题

下列C++代码的输出是什么（涉及静态成员和析构顺序的完整示例）
#include <iostream>
using namespace std;
class MyClass {
private: int id; static int count;
public:
MyClass(int id){ this->id=id; count++; cout << "Constructor: Object " << this->id << " created. Total objects: " << count << endl; }
~MyClass() { count--; cout << "Destructor: Object " << this->id << " destroyed. Total objects: " << count << endl; }
void showId() const { cout << "Object ID: " << this->id << endl; }
static int getCount() { return count; }
};
int MyClass::count = 0;
int main() { MyClass obj1(1); { MyClass obj2(2); obj2.showId(); } cout << "Total objects after block: " << MyClass::getCount() << endl; return 0; }

- **A.** Constructor: Object 1 created. Total objects: 1
- **B.** (不同顺序)
- **C.** (不同计数)
- **D.** (不同顺序和计数)

> **标准答案：A**

---

> 共 20 题 | 来源：Matrix 程序设计Ⅱ