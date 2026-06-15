#include "Num.h"
#include<algorithm>
using namespace std;

int Solution::singleNumber(vector<int>& nums){
    int result = 0;
    for(int num : nums) {
        result ^= num;
    }
    return result;
}
