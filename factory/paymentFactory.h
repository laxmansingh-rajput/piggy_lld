#include <bits/stdc++.h>
#include "../strategies/PaymentStrategy.h"

class Payment_strategy_factory
{
public:
    PaymentStrategy *create_payment_stragtegy(string s)
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