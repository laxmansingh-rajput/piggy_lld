
#ifndef Paymentstrategyfactory_H
#define Paymentstrategyfactory_H

#include <bits/stdc++.h>
#include "../strategies/PaymentStrategy.h"
#include "../interface/Payment.h"

class Payment_strategy_factory
{
public:
    PaymentStrategy *create_payment_strategy(string s)
    {
        if (s == "UPI")
        {
            return new UPI();
        }
        else
        {
            return new Net_Banking();
        }
    }
};
#endif