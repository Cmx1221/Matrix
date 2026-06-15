#include "Match.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    Solution solution;
    vector<string> words;
    string pattern;
    string input;

    // 输入单词列表
    getline(cin, input);
    istringstream iss(input);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    // 输入模式
    cin >> pattern;

    // 查找匹配的单词
    vector<string> result = solution.findAndReplacePattern(words, pattern);

    // 输出结果
    if (result.empty()) {
        cout << "empty" << endl;
    } else {
        for (const auto& w : result) {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}
