#include <iostream>
#include <string>
#include <iomanip>
#include "utils.hpp"

using namespace std;
int main() {
    string type, bits;
    while (cin >> type >> bits) {
        if (type == "INT") {
            cout << decode_bits<int>(bits) << endl;
        } else if (type == "FLOAT") {
            cout << fixed << setprecision(4) << decode_bits<float>(bits) << endl;
        } else if (type == "DOUBLE") {
            cout << fixed << setprecision(4) << decode_bits<double>(bits) << endl;
        }
    }
    return 0;
}
