#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
using namespace std;

template<typename T>
T decode_bits(const string& bits);

extern template int decode_bits<int>(const string&);
extern template float decode_bits<float>(const string&);
extern template double decode_bits<double>(const string&);

#endif
