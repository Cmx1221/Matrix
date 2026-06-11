#include "devices.h"
#include <algorithm>
#include <iostream>
#include <typeinfo>

using namespace std;

vector<Device*> devices;


static bool isType(Device* d, const string& t) {
    if (t == "Laptop") return typeid(*d) == typeid(Laptop);
    if (t == "Desktop") return typeid(*d) == typeid(Desktop);
    return typeid(*d) == typeid(Printer);
}


int totalPower() {
    int s = 0;
    for (auto d : devices) s += d->getPower();
    return s;
}

int countN(const string& t) {
    int c = 0;
    for (auto d : devices)
        if (isType(d, t)) c++;
    return c;
}

int countL(const string& t) {
    int s = 0;
    for (auto d : devices)
        if (isType(d, t)) s += d->getLife();
    return s;
}


static int priority(const string& t) {
    if (t == "Laptop") return 3;
    if (t == "Desktop") return 2;
    return 1;
}


string maxN() {
    int lc = countN("Laptop");
    int dc = countN("Desktop");
    int pc = countN("Printer");

    if (lc + dc + pc == 0) return "NO";

    int mx = max({lc, dc, pc});

    string best = "";
    int bestP = -1;

    if (lc == mx) { best = "Laptop"; bestP = priority("Laptop"); }
    if (dc == mx && priority("Desktop") > bestP) {
        best = "Desktop"; bestP = priority("Desktop");
    }
    if (pc == mx && priority("Printer") > bestP) {
        best = "Printer"; bestP = priority("Printer");
    }

    return best + " " + to_string(mx);
}


string minN() {
    int lc = countN("Laptop");
    int dc = countN("Desktop");
    int pc = countN("Printer");

    if (lc + dc + pc == 0) return "NO";

    int mn = min({lc, dc, pc});

    string best = "";
    int bestP = -1;

    if (lc == mn) { best = "Laptop"; bestP = priority("Laptop"); }
    if (dc == mn && priority("Desktop") > bestP) {
        best = "Desktop"; bestP = priority("Desktop");
    }
    if (pc == mn && priority("Printer") > bestP) {
        best = "Printer"; bestP = priority("Printer");
    }

    return best + " " + to_string(mn);
}


string maxL() {
    int lc = countL("Laptop");
    int dc = countL("Desktop");
    int pc = countL("Printer");

    if (lc + dc + pc == 0) return "NO";

    int mx = max({lc, dc, pc});

    string best = "";
    int bestP = -1;

    if (lc == mx) { best = "Laptop"; bestP = priority("Laptop"); }
    if (dc == mx && priority("Desktop") > bestP) {
        best = "Desktop"; bestP = priority("Desktop");
    }
    if (pc == mx && priority("Printer") > bestP) {
        best = "Printer"; bestP = priority("Printer");
    }

    return best + " " + to_string(mx);
}


string minL() {
    int lc = countL("Laptop");
    int dc = countL("Desktop");
    int pc = countL("Printer");

    if (lc + dc + pc == 0) return "NO";

    int mn = min({lc, dc, pc});

    string best = "";
    int bestP = -1;

    if (lc == mn) { best = "Laptop"; bestP = priority("Laptop"); }
    if (dc == mn && priority("Desktop") > bestP) {
        best = "Desktop"; bestP = priority("Desktop");
    }
    if (pc == mn && priority("Printer") > bestP) {
        best = "Printer"; bestP = priority("Printer");
    }

    return best + " " + to_string(mn);
}


void use(const string& t) {
    if (devices.empty()) {
        cout << "NO\n";
        return;
    }

    int idx = -1;
    Device* target = nullptr;
    int maxLife = -1;

    for (int i = 0; i < (int)devices.size(); i++) {
        if (!isType(devices[i], t)) continue;

        int life = devices[i]->getLife();

        if (life > maxLife) {
            maxLife = life;
            target = devices[i];
            idx = i;
        }
    }

    if (!target) {
        cout << "NO\n";
        return;
    }

    if (t == "Laptop")
        static_cast<Laptop*>(target)->use();
    else if (t == "Desktop")
        static_cast<Desktop*>(target)->use();
    else
        static_cast<Printer*>(target)->use();

    if (target->getLife() <= 0) {
        delete target;
        devices.erase(devices.begin() + idx);
    }
}


void typeCheck() {
    if (devices.empty()) {
        cout << "NO\n";
        return;
    }

    cout << "Laptop:" << countN("Laptop") << "\n";
    cout << "Desktop:" << countN("Desktop") << "\n";
    cout << "Printer:" << countN("Printer") << "\n";
}
