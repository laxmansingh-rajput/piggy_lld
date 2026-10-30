#ifndef OrderService_H
#define OrderService_H
#include <bits/stdc++.h>
#include "../factory/OrderFactory.h"
#include "../factory/PaymentFactory.h"
#include "../interface/Payment.h"
#include "../model/Order.h"
using namespace std;

class OrderService
{
    PaymentFactory *payment_factory;
    OrderFactory *order_factory;

public:
    OrderService()
    {
        payment_factory = new PaymentFactory();
        order_factory = new OrderFactory();
    }
    Order *createOrder(string order_type, float Amount, string payment_type, unordered_map<MenuItem *, int> items)
    {
        Payment *p = payment_factory->Create_Payment(Amount, payment_type);
        Order *order = order_factory->CreateOrder(order_type, Amount, items, p);
        return order;
        // string s, float Amount, vector<MenuItem *> items, Payment *p
    }
    void PayForOrder()
    {
    }
};
#endif