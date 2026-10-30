#include <bits/stdc++.h>
#include "../strategies/PaymentStrategy.h"
#include "../factory/PaymentFactory.h"

class Payment
{
public:
    bool status = false;
    float amount;
    PaymentStrategy *s = nullptr;

    Payment(float amount, string strategy)
    {
        this->amount = amount;
        Change_startegy(strategy);
    }

    void Pay(int id, int password, bool &status)
    {
        s->pay(amount, id, password, status);
    }

    void Change_startegy(string payment_type)
    {
        Payment_strategy_factory *p = new Payment_strategy_factory();
        if (s)
            delete s;
        s = p->create_payment_stragtegy(payment_type);
        delete p;
    }
};