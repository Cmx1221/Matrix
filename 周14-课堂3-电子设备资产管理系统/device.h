#ifndef DEVICE_H
#define DEVICE_H

#include <string>
using namespace std;

class Device {
public:
    virtual int getPower() const = 0;
    virtual int getLife() const = 0;
    virtual ~Device(){}
};

class Usable {
public:
    virtual void use() = 0;
    virtual ~Usable(){}
};

#endif
