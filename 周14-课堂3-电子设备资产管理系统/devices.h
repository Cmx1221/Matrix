#ifndef DEVICES_H
#define DEVICES_H

#include "device.h"

class Laptop final : public Device, public Usable {
    int power = 60;
    int life = 180;
public:
    int getPower() const override { return power; }
    int getLife() const override { return life; }
    void use() override { life -= power; }
};

class Desktop final : public Device, public Usable {
    int power = 120;
    int life = 360;
public:
    int getPower() const override { return power; }
    int getLife() const override { return life; }
    void use() override { life -= power; }
};

class Printer final : public Device, public Usable {
    int power = 80;
    int life = 240;
public:
    int getPower() const override { return power; }
    int getLife() const override { return life; }
    void use() override { life -= power; }
};

#endif
