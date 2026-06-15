# 字谜猎手 (Anagram Hunter)

## 题目来源

程设Ⅱ - 周16 - 课后4（选做）

## 题目描述

给定一个包含多个单词的字典 (例如，一个 `std::vector<std::string>` )。你的任务是找出这个字典中所有字谜 (Anagrams) 组合。字谜是指由相同字母但顺序不同的单词组成的词语（例如："listen" 和 "silent" 是字谜）。

## 任务要求

编写一个C++函数 `findAnagrams` ，该函数接受一个 `const std::vector<std::string>& dictionary` 作为输入。函数需要将字典中的字谜分组。

## 输出示例

如果输入字典包含 `{"listen", "silent", "enlist", "rat", "tar", "art", "banana"}` ，则输出（或返回的数据结构表示）可能如下：

```
listen, silent, enlist
rat, tar, art
banana
```

## 核心STL运用提示

- 使用 `std::map` ，其键可以是单词中字符排序后的版本（作为字谜的唯一标识），值可以是一个 `std::vector<std::string>` (或 `std::set<std::string>` )，用于存储所有具有该相同排序字符版本的原始单词。
- 需要对字符串中的字符进行排序以生成键。

## 输入输出示例

输入：
```
listen silent enlist rat tar art banana
```

输出：
```
rat, tar, art
listen, silent, enlist
```

## 输出顺序说明

- **组间顺序**：按每组规范化字符串（即单词排序后的字母串）的字典序升序输出（例如示例中 `"aert"` 对应 rat/tar/art 组先于 `"eilnst"` 对应 listen/silent/enlist 组输出）
- **组内顺序**：按单词在输入中首次出现的先后顺序输出（例如示例中 rat 先于 tar 先于 art 出现在输入中，因此组内输出顺序为 rat, tar, art）
- 单个单词（没有其他字谜）不输出（例如示例中的 banana 没有出现在输出中）
- 如果没有找到任何字谜组，输出一行：`没有找到字谜组.`

## 限制

- 时间限制：1000 ms
- 内存限制：32 MB

## 文件结构

```
├── anagram_utils.h    # 函数声明
├── anagram_utils.cpp  # 函数实现
├── main.cpp           # 主程序
└── README.md          # 题目说明
```
