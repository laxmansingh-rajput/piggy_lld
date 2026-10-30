#ifndef OrderFactory_H
#define OrderFactory_H
#include <bits/stdc++.h>
#include "../model/Order.h"
#include "../model/MenuItem.h"
#include "../interface/Payment.h"

class OrderFactory
{
    static int object_created;

public:
    Order *CreateOrder(string s, float Amount, unordered_map<MenuItem *, int> items, Payment *p)
    {
        if (s == "Delivery")
        {
            // int order_id, float Amount, vector<MenuItem *> items, Payment *p;
            return new Delivery_Order(++object_created, Amount, items, p);
        }
        else
        {
            return new Pickup_Order(++object_created, Amount, items, p);
        }
    }
};

int OrderFactory::object_created = 0;
#endif