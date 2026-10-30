#include <bits/stdc++.h>
#include "../model/Order.h"

class OrderFactory
{
public:
    static int object_created = 0;
    Order *CreateOrder(string s, float Amount, vector<int> items, Payment *p)
    {
        if (s == "Delivery")
        {
            return new Delivery_Order(Amount, items, ++objectCreated, Payment * p);
        }
        else
        {
            return new Pickup_Order(Amount, items, ++objectCreated, Payment * p);
        }
    }
};