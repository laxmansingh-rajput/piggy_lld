#ifndef PaymentFactory_H
#define PaymentFactory_H

#include <bits/stdc++.h>
#include "../strategies/PaymentStrategy.h"
#include "./PayementStrategyFactory.h"

#include "../interface/Payment.h"

class PaymentFactory
{
    Payment_strategy_factory *strategy_factory;

public:
    PaymentFactory()
    {
        strategy_factory = new Payment_strategy_factory();
    }
    Payment *Create_Payment(float amount, string type)
    {
        PaymentStrategy *strategy = strategy_factory->create_payment_strategy(type);
        return new Payment(amount, type, strategy);
    }
};
#endif