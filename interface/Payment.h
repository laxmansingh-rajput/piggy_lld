#ifndef Payment_H
#define Payment_H

#include <bits/stdc++.h>
#include "../strategies/PaymentStrategy.h"
#include "../factory/PayementStrategyFactory.h"

using namespace std;

class Payment
{
    bool status = false;
    float amount;
    string strategy;
    PaymentStrategy *s = nullptr;

public:
    Payment(float amount, string strategy, PaymentStrategy *s)
    {
        this->amount = amount;
        this->s = s;
        this->strategy = strategy;
        Change_strategy(strategy);
    }

    // Getters
    bool get_status() const
    {
        return status;
    }
    string Get_Payment_Type() const
    {
        return strategy;
    }

    float get_amount() const
    {
        return amount;
    }

    PaymentStrategy *get_strategy() const
    {
        return s;
    }

    // Setters
    void set_status(bool status)
    {
        this->status = status;
    }

    void set_amount(float amount)
    {
        this->amount = amount;
    }

    void set_strategy(PaymentStrategy *s)
    {
        this->s = s;
    }

    void Pay(int id, int password)
    {
        s->pay(amount, id, password, status);
        this->status = status;
    }

    void Change_strategy(string payment_type)
    {
        Payment_strategy_factory *p = new Payment_strategy_factory();
        this->strategy = payment_type;

        s = p->create_payment_strategy(payment_type);

        delete p;
    }
};
#endif