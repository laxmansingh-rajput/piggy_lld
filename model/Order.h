#include <bits/stdc++.h>
#include "./MenuItem.h"
#include "./Menu.h"
#include "../interface/Payment.h"
using namespace std;

class Order
{
public:
    int order_id;
    float Amount;
    vector<MenuItem *> items;
    Payment *p;
    Order(int order_id, float Amount, vector<MenuItem *> items, Payment *p)
    {
        this->items = items;
        this->order_id = order_id;
        this->Amount = Amount;
        this->p = p;
    }
    virtual void Initiate_Order_Lifecycle() = 0;
};

class Delivery_Order : public Order
{
public:
    Delivery_Order(int order_id, float Amount,
                   vector<MenuItem *> items, Payment *p)
        : Order(order_id, Amount, items, p)
    {
    }
    void Initiate_Order_Lifecycle() override
    {
    }
};

class Pickup_Order : public Order
{
public:
    Pickup_Order(int order_id, float Amount,
                 vector<MenuItem *> items, Payment *p)
        : Order(order_id, Amount, items, p)
    {
    }
    void Initiate_Order_Lifecycle() override
    {
    }
};