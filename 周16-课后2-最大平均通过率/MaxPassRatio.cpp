#include "MaxPassRatio.hpp"
#include <iostream>
#include<cstring>
#include <algorithm>
using namespace std;

struct Node {
    int pass, total;

    double gain() const {
        return (double)(pass + 1) / (total + 1)
             - (double)pass / total;
    }

    bool operator<(const Node& other) const {
        return gain() < other.gain(); // 大根堆
    }
};

double maxPassRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<Node> pq;

    for (auto &c : classes) {
        pq.push({c[0], c[1]});
    }

    while (extraStudents--) {
        Node cur = pq.top(); pq.pop();

        cur.pass++;
        cur.total++;

        pq.push(cur);
    }

    double ans = 0;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        ans += (double)cur.pass / cur.total;
    }

    return ans / classes.size();
}
