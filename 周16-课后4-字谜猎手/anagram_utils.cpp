#include "anagram_utils.h"
#include <iostream>
#include<algorithm>

using namespace std;

std::string getCanonicalForm(const std::string& word){
    string str = word;
    sort(str.begin(),str.end());
    return str;
}


std::map<std::string, std::vector<std::string>> findAnagrams(const std::vector<std::string>& dictionary) {

    std::map<std::string, std::vector<std::string>> ans;

    for (const auto& word : dictionary) {
        ans[getCanonicalForm(word)].push_back(word);
    }

    return ans;
}

void printAnagramGroups(const std::map<std::string, std::vector<std::string>>& anagram_groups){

    int flag = 0;
    for(auto p = anagram_groups.begin();p!=anagram_groups.end();p++){
        if(p->second.size() == 1) continue;
        for(auto j = p->second.begin();j!=p->second.end()-1;j++){
            cout << *j << ", ";
            flag = 1;
        }
        cout << *(p->second.end()-1) << endl;
    }
    if(!flag){
        cout << "没有找到字谜组." << endl;
    }
}
