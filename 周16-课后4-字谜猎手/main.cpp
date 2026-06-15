#include "anagram_utils.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> dictionary; // 用于存储从输入读取的单词
    std::string word;

    while (std::cin >> word) {
        if (word.empty()) {
            continue;
        }
        dictionary.push_back(word);
    }

    auto anagram_groups = findAnagrams(dictionary);
    printAnagramGroups(anagram_groups);

    return 0;
}
