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

> 共 10 题 | 来源：Matrix 程序设计Ⅱ