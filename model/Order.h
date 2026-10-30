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
    Order(int order_id, float Amount, vector<int> items, , Payment *p)
    {
        this->order_id = order_id;
        this->Amount = Amount;
        this->p = p;
    }
    virtual void Initiate_Order_Lifecycle() = 0;
};

class Delivery_Order : pulic Order
{
    Delivery_Order(int order_id, float Amount, vector<int> items, , Payment *p)
    {
        this->order_id = order_id;
        this->Amount = Amount;
        this->p = p;
    }
    void virtual void Initiate_Order_Lifecycle() overide
    {
    }
};

class Pickup_order : public Order
{
    Pickup_Order(int order_id, float Amount, vector<int> items, , Payment *p)
    {
        this->order_id = order_id;
        this->Amount = Amount;
        this->p = p;
    }
    void virtual void Initiate_Order_Lifecycle() overide
    {
    }
};