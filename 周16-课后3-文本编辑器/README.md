# 文本编辑器

## 题目来源

程设Ⅱ - 周16 - 课后3（选做）

## 题目描述

你正在开发一个极简的文本编辑器。目前，它支持在文档末尾追加新的文本行，撤销和重做功能。编辑器将当前文档内容维护为一个字符串列表。

## 任务要求

实现 `TextEditor` 类，包含以下方法：

- **`append(const std::string& line)`** :
  - 行为：在文档末尾添加一行文本。此操作应记录下来，以便后续可以撤销。执行新的 `append` 操作后，所有先前的"重做"历史应被清除。

- **`undo()`** :
  - 行为：撤销上一次的 `append` 操作。如果文档为空或没有可撤销的操作，则不执行任何操作。

- **`redo()`** :
  - 行为：重做上一次被撤销的 `append` 操作。如果没有可重做的操作，则不执行任何操作。

- **`getDocument() const`** :
  - 行为：返回当前文档的所有行。
  - 返回：`std::vector<std::string>` (或者 `std::list<std::string>` )。

## 核心STL运用提示

- 使用 `std::list<std::string>` (或 `std::vector<std::string>`) 存储当前文档内容。
- 使用两个 `std::list<std::string>` (或类似结构) 分别作为 `undoStack` 和 `redoStack` ，用于存储被添加或移除的文本行，以支持撤销和重做操作。

## 输入输出示例

输入：
```
first line
second line
third new line
```

输出：
```
first line
second line
first line
(empty)
(empty)
first line
first line
second line
first line
second line
first line
second line
third new line
first line
second line
third new line
first line
second line
```

## 限制

- 时间限制：1000 ms
- 内存限制：32 MB

## 文件结构

```
├── TextEditor.h    # 类声明
├── TextEditor.cpp  # 类实现
├── main.cpp        # 主程序
└── README.md       # 题目说明
```
