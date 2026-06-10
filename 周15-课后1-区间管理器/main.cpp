#include "Manager.hpp"
#include <iostream>
#include <string>

int main() {
    IntervalManager<int, 10>    intMgr;
    IntervalManager<double, 5>  doubleMgr;

    std::string type;
    while (std::cin >> type) {
        if (type == "INT") {
            int s, e;
            std::cin >> s >> e;
            intMgr.add(s, e);
            intMgr.query();
        } else if (type == "DOUBLE") {
            double s, e;
            std::cin >> s >> e;
            doubleMgr.add(s, e);
            doubleMgr.query();
        }
    }

    return 0;
}
