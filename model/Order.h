#ifndef Order_H
#define Order_H

#include <bits/stdc++.h>
#include "./MenuItem.h"
#include "./Menu.h"
#include "../interface/Payment.h"
using namespace std;

class Order
{
    int order_id;
    float Amount;
    unordered_map<MenuItem *, int> items;
    Payment *p;

public:
    Order(int order_id, float Amount, unordered_map<MenuItem *, int> items, Payment *p)
    {
        this->items = items;
        this->order_id = order_id;
        this->Amount = Amount;
        this->p = p;
    }

    // Getters
    int get_order_id() const
    {
        return order_id;
    }

    float get_amount() const
    {
        return Amount;
    }

    unordered_map<MenuItem *, int> get_items() const
    {
        return items;
    }

    Payment *get_payment() const
    {
        return p;
    }

    // Setters
    void set_order_id(int order_id)
    {
        this->order_id = order_id;
    }

    void set_amount(float Amount)
    {
        this->Amount = Amount;
    }

    void set_items(unordered_map<MenuItem *, int> items)
    {
        this->items = items;
    }

    void set_payment(Payment *p)
    {
        this->p = p;
    }

    virtual void Initiate_Order_Lifecycle() = 0;

    virtual ~Order() = default;
};

class Delivery_Order : public Order
{
public:
    Delivery_Order(int order_id, float Amount,
                   unordered_map<MenuItem *, int> items, Payment *p)
        : Order(order_id, Amount, items, p)
    {
    }
    void Initiate_Order_Lifecycle() override
    {
        cout << "Notifing the user, deliverPartner and restaurent regarding the order" << endl;
    }
};

class Pickup_Order : public Order
{
public:
    Pickup_Order(int order_id, float Amount,
                 unordered_map<MenuItem *, int> items, Payment *p)
        : Order(order_id, Amount, items, p)
    {
    }
    void Initiate_Order_Lifecycle() override
    {
        cout << "Notifing the user and restaurent regarding the order" << endl;
    }
};

#endif