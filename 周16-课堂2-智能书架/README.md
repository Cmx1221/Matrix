# 智能书架接口设计

## 题目来源

程设Ⅱ - 周16 - 课堂2

## 题目描述

你正在为一个数字图书馆项目设计一个"智能书架" (`SmartBookshelf`)。这个书架需要能够管理一系列书籍 (`Book`)。每本书籍包含以下信息：书名 (title, `std::string` )、作者 (author, `std::string` )、ISBN (国际标准书号, `std::string` ，唯一标识符) 和出版年份 (publicationYear, `int` )。

`SmartBookshelf.hpp` 头文件提供 `Book` 类定义以及 `SmartBookshelf` 类的声明。你还需实现以下接口：

### 添加书籍 (`addBook`)

- 输入：一个 `Book` 对象。
- 操作：将书籍添加到书架。如果已存在相同ISBN的书籍，则添加失败，并输出 `ISBN 'book.isbn' exists` 。
- 返回：`bool` 值， `true` 表示添加成功，并输出 `"addBook success"`， `false` 表示失败（例如ISBN重复）。
- 如果 `isbn` 为空，输出：`empty ISBN！`

### 移除书籍 (`removeBook`)

- 输入：书籍的ISBN (`const std::string&` )。
- 操作：根据ISBN从书架移除书籍。
- 返回：`bool` 值， `true` 表示移除成功， `false` 表示未找到对应ISBN的书籍。
- 如果 `isbn` 为空，输出：`empty ISBN！` 并返回 `false`
- 如果没有找到对应 ISBN 的书籍，输出：`ISBN '对应ISBN' not found` ，并返回 `false` 。
- 如果移除成功，输出：`removeBook success` ，并返回 `true` 。

### 查找书籍 (`findBookByISBN`)

- 输入：书籍的ISBN (`const std::string&` )。
- 操作：根据ISBN查找书籍。
- 如果 `isbn` 为空，输出：`empty ISBN！` ，并返回 `nullptr` 。
- 如果找到对应书籍，输出：`ISBN '对应ISBN' title:对应书名` 并返回：`const Book*` (指向找到的Book对象的常量指针)。
- 如果未找到，输出 `ISBN '对应isbn' not found` ，并返回 `nullptr` 。

## 输入输出示例

输入：
```
1984 George 978-0451524935 1949
Kill Harper 978-0061120084 1960
Another Author 978-0618260274 2000
```

输出：
```
addBook success
addBook success
addBook success
3
ISBN '978-0451524935' title:1984
ISBN '000-0000000000' not found
removeBook success
2
ISBN '111-1111111111' not found
2
ISBN '978-0451524935' not found
Book not found.
empty ISBN！
empty ISBN！
empty ISBN！
```

## 限制

- 时间限制：1000 ms
- 内存限制：32 MB

## 文件结构

```
├── SmartBookshelf.h    # 类声明和Book结构体
├── SmartBookshelf.cpp  # 类实现
├── main.cpp            # 主程序
└── README.md           # 题目说明
```
