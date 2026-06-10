#include "Manager.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

// ---------- 辅助：长度比较（double 加 epsilon 容差） ----------
bool lenShorter(int a, int b)    { return a < b; }
bool lenEqual(int a, int b)      { return a == b; }
bool lenShorter(double a, double b) { return a < b - 1e-9; }
bool lenEqual(double a, double b)   { return std::abs(a - b) < 1e-9; }

// ---------- 辅助：格式化输出 ----------
// 利用模板特化区分 int（默认格式）和 double（定点 1 位小数）
template <typename T>
struct FormatHelper {
    static void apply(std::ostream &) { /* int: 默认格式 */ }
    static void reset(std::ostream &) { /* int: 无需恢复 */ }
};

template <>
struct FormatHelper<double> {
    static void apply(std::ostream &os) {
        os << std::fixed << std::setprecision(1);
    }
    static void reset(std::ostream &os) {
        os << std::defaultfloat;
    }
};

// ---------- 实现 ----------

template <typename T, int Limit>
IntervalManager<T, Limit>::IntervalManager() : count(0) {}

template <typename T, int Limit>
void IntervalManager<T, Limit>::add(T s, T e) {
    // 确保 s <= e
    if (s > e) {
        T tmp = s;
        s = e;
        e = tmp;
    }

    // 将现有区间 + 新区间拷贝到临时工作数组（大小 Limit+1，防止越界）
    Segment<T> work[Limit + 1];
    for (int i = 0; i < count; i++) {
        work[i] = data[i];
    }
    work[count].start = s;
    work[count].end   = e;
    int n = count + 1;

    // 按 start 升序排序（冒泡）
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (work[j].start > work[j + 1].start) {
                Segment<T> tmp  = work[j];
                work[j]         = work[j + 1];
                work[j + 1]     = tmp;
            }
        }
    }

    // 合并有交集或端点重合的区间
    int m = 0;
    int i = 0;
    while (i < n) {
        T curS = work[i].start;
        T curE = work[i].end;
        int j = i + 1;
        while (j < n && work[j].start <= curE) {
            if (work[j].end > curE) {
                curE = work[j].end;
            }
            j++;
        }
        work[m].start = curS;
        work[m].end   = curE;
        m++;
        i = j;
    }
    n = m;

    // 容量超限淘汰：删除长度最短的区间（平局删 start 更小的）
    while (n > Limit) {
        int worst     = 0;
        T   worstLen  = work[0].end - work[0].start;
        for (int k = 1; k < n; k++) {
            T len = work[k].end - work[k].start;
            if (lenShorter(len, worstLen) ||
                (lenEqual(len, worstLen) && work[k].start < work[worst].start)) {
                worst    = k;
                worstLen = len;
            }
        }
        for (int k = worst; k < n - 1; k++) {
            work[k] = work[k + 1];
        }
        n--;
    }

    // 拷回 data
    for (int k = 0; k < n; k++) {
        data[k] = work[k];
    }
    count = n;
}

template <typename T, int Limit>
void IntervalManager<T, Limit>::query() {
    // 按 start 升序排序（冒泡）
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (data[j].start > data[j + 1].start) {
                Segment<T> tmp  = data[j];
                data[j]         = data[j + 1];
                data[j + 1]     = tmp;
            }
        }
    }

    // double 保留 1 位小数
    FormatHelper<T>::apply(std::cout);

    for (int i = 0; i < count; i++) {
        if (i > 0) std::cout << " ";
        std::cout << "[" << data[i].start << "," << data[i].end << "]";
    }
    std::cout << std::endl;

    // 恢复默认格式（以防影响后续 int 输出）
    FormatHelper<T>::reset(std::cout);
}

// ---------- 显式实例化 ----------
template class IntervalManager<int, 10>;
template class IntervalManager<double, 5>;
