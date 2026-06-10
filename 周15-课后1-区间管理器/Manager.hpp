#ifndef MANAGER_HPP
#define MANAGER_HPP

template <typename T>
struct Segment {
    T start;
    T end;
};

template <typename T, int Limit>
class IntervalManager {
private:
    Segment<T> data[Limit];
    int count;

public:
    IntervalManager();
    void add(T s, T e);
    void query();
};

extern template class IntervalManager<int, 10>;
extern template class IntervalManager<double, 5>;

#endif
