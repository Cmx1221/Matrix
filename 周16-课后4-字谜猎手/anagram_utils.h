#ifndef ANAGRAM_UTILS_H
#define ANAGRAM_UTILS_H

#include <string>
#include <vector>
#include <map>

std::string getCanonicalForm(const std::string& word);

std::map<std::string, std::vector<std::string>> findAnagrams(const std::vector<std::string>& dictionary);

void printAnagramGroups(const std::map<std::string, std::vector<std::string>>& anagram_groups);

#endif
