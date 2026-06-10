#include <string>
#include "utils.hpp"
using namespace std;

using byte4 = unsigned int;
using byte8 = unsigned long long;

template<typename T>
T decode_bits(const string& bits) {
    if (sizeof(T) == 4) {
        byte4 bitValues = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] == '1') {
                bitValues |= (1U << (31 - i));
            }
        }
        return *(T*)&bitValues;
    } else {
        byte8 bitValues = 0;
        for (int i = 0; i < 64; i++) {
            if (bits[i] == '1') {
                bitValues |= (1ULL << (63 - i));
            }
        }
        return *(T*)&bitValues;
    }
}

template int decode_bits<int>(const string&);
template float decode_bits<float>(const string&);
template double decode_bits<double>(const string&);
