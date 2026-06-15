#include "Match.h"
#include <vector>
#include <string>
#include <sstream>
#include<algorithm>
using namespace std;


vector<string> Solution::findAndReplacePattern(vector<string>& words, string pattern){
    vector<string> ans;
    int len = pattern.size();
    int flag = 0;
    for(auto p:words){
        for(int i = 0;i<len;i++){
            int m = p.find(p[i]);
            int n = pattern.find(pattern[i]);
            if(m != n) flag = 1;
        }
        if(!flag) ans.push_back(p);
        flag = 0;
    }
    if(ans.empty()) return vector<string>();

    return ans;
}
