#ifndef PaymentStrategy_H
#define PaymentStrategy_H
#include <bits/stdc++.h>
using namespace std;
class PaymentStrategy
{
public:
    virtual void pay(float amount, int id, int password, bool &status) = 0;
};
class UPI : public PaymentStrategy
{
public:
    void pay(float amount, int id, int password, bool &status) override
    {
        cout << "Amount of " << amount << " is Payed By UPI" << endl;
        status = true;
    }
};

class Net_Banking : public PaymentStrategy
{
public:
    void pay(float amount, int id, int password, bool &status) override
    {
        cout << "Amount of " << amount << " is Payed By Net Banking" << endl;
        status = true;
    }
};
#endif