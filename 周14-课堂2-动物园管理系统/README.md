# 动物园管理系统

## 题目来源

程设Ⅱ - 周14 - 课堂2

## 题目描述

继承抽象类 `Animal`，实现四种动物：

| 动物 | 叫声 | 每天食物消耗 |
|------|------|-------------|
| Dog | Woof | 5 |
| Cat | Meow | 3 |
| Cow | Moo | 10 |
| Sheep | Baa | 7 |

### 支持命令

| 命令 | 说明 |
|------|------|
| ADD type | 增加一只动物 |
| SPEAK | 所有动物按加入顺序发声 |
| FEED | 输出总食物消耗 |
| COUNT type | 统计某动物数量 |
| TYPECHECK | 用 RTTI 统计各动物 |
| EXIT | 结束，释放内存 |

## 输入格式

第一行 `n` 表示操作数量，接下来 n 行命令。

## 输出格式

COUNT、FEED、SPEAK、TYPECHECK 按功能输出，其余不输出。

## 样例

### 输入
```
8
ADD Dog
ADD Cat
ADD Cow
COUNT Dog
FEED
TYPECHECK
SPEAK
EXIT
```

### 输出
```
1
18
Dog:1
Cat:1
Cow:1
Sheep:0
Woof
Meow
Moo
```

## 文件结构
```
├── main.cpp     # 完整代码
└── README.md    # 题目说明
```
