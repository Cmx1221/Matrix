# 程序设计Ⅱ - 周15 理论题

## 题目来源

程设Ⅱ - 周15 - 理论题

## 题目描述

覆盖泛型编程基础概念与静态多态本质、函数模板的类型推导与全特化规则等核心基础知识点，侧重考察编译期决议机制与语法边界陷阱。

---

### 第1题 - 单选题

关于泛型编程与模板的特征，下列说法错误的是？

- **A.** 泛型编程独立于任何特定数据类型
- **B.** 模板实例化（Instantiation）是由编译器在编译期完成的
- **C.** 泛型编程利用模板实现了动态多态性（运行时代态）
- **D.** 模板的代码只有在被具体类型实例化后，才会由编译器生成实际的机器代码

> **标准答案：C**

---

### 第2题 - 单选题

考虑以下函数模板声明：template <typename T> T foo(T a, T b);，在不考虑隐式类型转换的情况下，以下哪个调用会导致编译错误？

- **A.** foo(1, 2);
- **B.** foo(1.5, 2.5);
- **C.** foo(1, 2.5);
- **D.** foo<double>(1, 2.5);

> **标准答案：C**

---

### 第3题 - 单选题

下列关于函数模板特化（Specialization）的说法中，正确的是？

- **A.** 函数模板特化形式为 template <typename T> 后面跟特化函数定义
- **B.** 特化版本的函数体必须与主模板（基础模板）的实现逻辑完全一致
- **C.** 进行全特化时，template <> 后面的尖括号内不保留任何模板类型形参
- **D.** 编译器在匹配函数时，总是优先匹配基础模板，匹配不上才考虑特化版本

> **标准答案：C**

---

### 第4题 - 单选题

观察以下代码片段，该程序在编译运行后的输出结果是？
template <typename T>
void print(T x) { std::cout << 1; }
template <>
void print(int x) { std::cout << 2; }
void print(int x) { std::cout << 3; }
int main() {
print(10);
}

- **A.** 1
- **B.** 2
- **C.** 3
- **D.** 编译错误，函数重载定义冲突

> **标准答案：C**

---

### 第5题 - 单选题

在类模板的定义中，下列关于成员函数外部实现的语法，正确的是？

- **A.** void Stack<T>::push(T x) { ... }
- **B.** template <class T> void Stack::push(T x) { ... }
- **C.** template <typename T> void Stack<T>::push(T x) { ... }
- **D.** template <typename T> void Stack::push<T>(T x) { ... }

> **标准答案：C**

---

### 第6题 - 单选题

关于非类型模板形参（Non-type Template Parameters），下列说法正确的是？

- **A.** 任何自定义的类结构体对象（如 std::string）都可以直接作为非类型模板形参
- **B.** 非类型模板实参必须是编译期常量或常量表达式
- **C.** 非类型模板形参在模板类内部可以被当成普通变量进行动态修改
- **D.** 浮点数类型（如 float、double）在 C++11 标准中可以无条件直接作为非类型模板形参

> **标准答案：B**

---

### 第7题 - 单选题

设有类模板定义：template <typename T, int N> class Array { ... };，以下哪组对象的类型在编译期被认为是完全相同的类型？

- **A.** Array<int, 5> 与 Array<int, 10>
- **B.** Array<int, 5> 与 Array<double, 5>
- **C.** Array<int, 2 + 3> 与 Array<int, 5>
- **D.** Array<const int, 5> 与 Array<int, 5>

> **标准答案：C**

---

### 第8题 - 单选题

函数模板可以重载。若同时存在普通非模板函数和同名的函数模板，在参数完美匹配的情况下，编译器的重载决议（Overload Resolution）策略是？

- **A.** 优先选择非模板函数
- **B.** 优先选择函数模板的基础版本
- **C.** 优先选择函数模板的特化版本
- **D.** 编译器无法抉择，直接报编译歧义错误（Ambiguous Call）

> **标准答案：A**

---

### 第9题 - 单选题

考虑以下用于推导一维数组长度的函数模板：
template <typename T, int N>
void getLength(T (&arr)[N]) {
std::cout << N;
}
对于定义 int a[10];，调用 getLength(a); 时，模板形参 T 和 N 分别被推导为什么？

- **A.** T 是 int*，N 是 10
- **B.** T 是 int，N 是 10
- **C.** T 是 int[10]，N 无法推导
- **D.** 编译报错，无法通过引用传递数组

> **标准答案：B**

---

### 第10题 - 单选题

如果将上题的函数签名修改为 template <typename T, int N> void getLength(T arr[N])，调用 getLength(a); 会发生什么？

- **A.** 依然成功输出 10
- **B.** 编译期能够推导出 N，但无法推导出 T
- **C.** 编译错误，因为此时 arr 会退化（Decay）为指针，无法推导出数组长度 N
- **D.** 运行期发生段错误（Segmentation Fault）

> **标准答案：C**

---

### 第11题 - 单选题

观察以下关于类模板全特化的讨论，哪项陈述是错误的？

- **A.** 只有类模板可以进行全特化，函数模板只能重载不能特化
- **B.** 类模板全特化时，必须在类名后用尖括号显式指定具体类型参数
- **C.** 类模板的全特化版本可以定义与基础模板完全不同的成员变量和成员函数
- **D.** 特化一个类模板时，必须在其前面写上空模板参数列表 template <>

> **标准答案：A**

---

### 第12题 - 单选题

考虑以下代码，在编译时会发生什么情况？
template <int Size> class Buffer { int data[Size]; };
int main() { int n; std::cin >> n; Buffer<n> myBuf; }

- **A.** 编译成功，在运行期动态分配长度为 n 的静态数组
- **B.** 编译失败，因为非类型模板实参 n 是运行期变量，不是编译期常量
- **C.** 编译成功，但由于 n 未初始化，会导致运行时数据越界
- **D.** 只有当用户输入正整数时，编译才能成功

> **标准答案：B**

---

### 第13题 - 单选题

下列关于模板代码的头文件包含模式，说法最准确的是？

- **A.** 模板的声明和实现必须和普通类一样，分别放在 .h 和 .cpp 中独立编译
- **B.** 由于模板是编译期动态生成的代码源，通常将其声明与实现都写在同一个 .h 头文件中
- **C.** .cpp 文件中只要包含了模板的声明，不需要知道其实现细节就能成功完成链接
- **D.** 编译器在编译没有被任何地方实例化的模板源文件时，会生成完整的二进制目标代码

> **标准答案：B**

---

### 第14题 - 单选题

观察以下关于二维数组引用的形参推导模板：
template <typename T, int R, int C> void processMatrix(T (&matrix)[R][C]);
已知 double mat[3][5];，调用 processMatrix(mat); 后，R 和 C 的值分别是？

- **A.** R = 5, C = 3
- **B.** R = 3, C = 5
- **C.** R = 15，C 无法推导
- **D.** 编译错误，C++ 不支持多维数组引用的模板参数推导

> **标准答案：B**

---

### 第15题 - 单选题

下列哪种类型不能作为 C++11 标准下的非类型模板形参？

- **A.** char
- **B.** long long
- **C.** double
- **D.** 指针类型（如 int*）

> **标准答案：C**

---

### 第16题 - 单选题

在执行代码 template<typename T> void swap(T& a, T& b); 的显式实例化声明时，正确的语法是？

- **A.** template swap<int>(int&, int&);
- **B.** template void swap<int>(int&, int&);
- **C.** void swap<int>(int&, int&);
- **D.** template <> void swap<int>(int&, int&);

> **标准答案：B**

---

### 第17题 - 单选题

观察下面这段带有偏序匹配陷阱的重载代码，执行 foo(5); 后的输出结果是？
template <typename T> void foo(T x) { std::cout << "A"; }
template <typename T> void foo(T* x) { std::cout << "B"; }
template <> void foo(int x) { std::cout << "C"; }
int main() { foo(5); }

- **A.** A
- **B.** B
- **C.** C
- **D.** 编译产生歧义

> **标准答案：C**

---

### 第18题 - 单选题

接上题，如果我们在 main 函数中改为执行 int n = 10; foo(&n);，输出结果将变为？

- **A.** A
- **B.** B
- **C.** C
- **D.** 编译错误

> **标准答案：B**

---

### 第19题 - 单选题

下列关于类模板内使用 typename 的说法，正确的是？

- **A.** typename 和 class 在任何场景下都可以完全互换，没有任何区别
- **B.** 在类模板内部声明嵌套的从属依赖类型（Dependent Name）时，必须前置 typename 关键字
- **C.** typename 只能在非类型模板参数声明中使用
- **D.** 在实例化一个模板类对象时，必须显式书写 typename

> **标准答案：B**

---

### 第20题 - 单选题

设有模板声明：template <typename T, typename U> class Pair;。现在想要为两个参数类型相同（如都是 int，或都是 double）的情况编写专门的高效逻辑。在不使用类模板特化（超纲）的前提下，我们可以通过下列哪种方式通知编译器处理？

- **A.** 无法处理，必须引入偏特化
- **B.** 在成员函数内部通过编译期常量表达式 if constexpr (std::is_same_v<T, U>) 结合业务进行分支控制。
- **C.** 在主模板里直接限制 template <typename T, typename T> class Pair;
- **D.** 在构造函数中强制将 U 转换为 T

> **标准答案：B**

---

> 共 20 题 | 来源：Matrix 程序设计Ⅱ