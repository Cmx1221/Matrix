# 序列副本

## 题目来源

程设Ⅱ - 周7 - 课堂4

## 题目描述

设计 `Seq` 类管理动态整数序列：

### 数据成员
- `int n` — 序列长度
- `int* data` — 动态数组指针
- `static int total` — 存在对象个数

### 需要实现的函数
- `Seq(int n=0)` — 构造函数，total+1，n>0 时申请动态空间
- `Seq(const Seq& other)` — 深拷贝构造，total+1
- `~Seq()` — 析构函数，释放内存，total-1
- `void input()` — 读入 n 个整数
- `void set(int index, int value)` — 修改元素（下标从 0 开始）
- `int longestNonDec() const` — 最长连续不下降子段长度
- `int diffCount(const Seq& other) const` — 两序列对应位置不同元素个数
- `static int getCount()` — 返回当前对象个数

### 要求
- 不使用 vector、string 等现成容器
- 拷贝构造函数实现深拷贝
- longestNonDec() 和 diffCount() 体现 const 的使用

## 输入格式
```
n
n 个整数（空格分隔）
index value
```

## 输出格式
```
修改后原序列的最长连续不下降子段长度
副本序列的最长连续不下降子段长度
不同元素个数 对象个数
```

## 样例

### 输入1
```
5
1 2 2 1 3
0 9
```

### 输出1
```
2
3
1 2
```

## 文件结构
```
├── Seq.hpp      # 类声明
├── Seq.cpp      # 类实现
├── main.cpp     # 主程序
└── README.md    # 题目说明
```
