#ifndef MENUITEM_H
#define MENUITEM_H
#include <bits/stdc++.h>
#include "./Restaurent.h"
#include "../enum.h"
using namespace std;

class MenuItem
{
    string ItemName;
    int item_id;
    float price;
    int restarurent_id;
    Item_With current_handeler = Item_With::RESTAURANT;

public:
    MenuItem(int item_id, string ItemName, float price, int restarurent_id)
    {
        this->item_id = item_id;
        this->ItemName = ItemName;
        this->price = price;
        this->restarurent_id = restarurent_id;
    }

    // Getters
    int get_item_id() const
    {
        return item_id;
    }

    string get_ItemName() const
    {
        return ItemName;
    }

    float get_price() const
    {
        return price;
    }

    int get_restarurent_id() const
    {
        return restarurent_id;
    }

    Item_With get_current_handeler() const
    {
        return current_handeler;
    }

    // Setters
    void set_item_id(int id)
    {
        item_id = id;
    }

    void set_ItemName(const string &name)
    {
        ItemName = name;
    }

    void set_price(float price)
    {
        // should be protected in service layer
        this->price = price;
    }

    void set_current_handeler(Item_With handler)
    {
        current_handeler = handler;
    }
};
#endif