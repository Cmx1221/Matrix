#include <iostream>
#include <vector>
#include "MaxPassRatio.hpp"
using namespace std;

int main() {
    int extraStudents,n;
    cin>>extraStudents>>n;

    vector<vector<int>> classes(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> classes[i][0] >> classes[i][1];
    }

    double res = maxPassRatio(classes, extraStudents);
    cout << fixed << setprecision(3) << res;

    return 0;
}
