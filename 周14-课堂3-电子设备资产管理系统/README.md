# 电子设备资产管理系统

## 题目来源

程设Ⅱ - 周14 - 课堂3

## 题目描述

某公司需要管理一批电子设备。系统包含三种设备：

| 设备 | 功耗 | 初始寿命 |
|------|------|---------|
| Laptop | 60 | 180 |
| Desktop | 120 | 360 |
| Printer | 80 | 240 |

要求：继承 `Device` 抽象基类 + 实现 `Usable` 接口，派生 `Laptop final`、`Desktop final`、`Printer final`，统一保存在 `vector<Device*>` 中。

### 系统功能

| 命令 | 说明 |
|------|------|
| PURCHASE type | 购买设备 |
| TOTAL | 总功耗 |
| COUNT_N type | 某类型数量（dynamic_cast） |
| COUNT_L type | 某类型总寿命 |
| MAX_N | 数量最多类型 |
| MIN_N | 数量最少类型 |
| MAX_L | 总寿命最大类型 |
| MIN_L | 总寿命最小类型 |
| USE type | 使用设备（life-power，≤0 则删除） |
| TYPECHECK | 用 typeid 统计各类型 |
| END | 结束 |

- 优先级固定：Laptop > Desktop > Printer
- 系统为空时多项输出 "NO"

## 输入格式

若干条命令，以 END 结束。

## 输出格式

根据输入命令要求输出。

## 样例

### 输入
```
PURCHASE Laptop
PURCHASE Laptop
PURCHASE Desktop
PURCHASE Printer
TOTAL
COUNT_N Laptop
COUNT_L Laptop
USE Laptop
COUNT_L Laptop
TYPECHECK
MAX_N
MIN_L
END
```

### 输出
```
320
2
360
300
Laptop:2
Desktop:1
Printer:1
Laptop 2
Printer 240
```

## 文件结构
```
├── device.h    # 抽象基类 + 接口声明
├── devices.h   # 派生类声明
├── devices.cpp # 功能实现
├── main.cpp    # 主程序
└── README.md   # 题目说明
```
