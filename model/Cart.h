#include <bits/stdc++.h>
#include "./MenuItem.h"
using namespace std;

class Cart
{
    static int nextId;
    int cart_id;
    int user_id;
    unordered_map<MenuItem *, int>
        cart_items;

public:
    Cart()
    {
        cart_id = nextId++;
    }
    void Add_To_Cart(MenuItem *item)
    {
        cart_items[item]++;
    }
    void Remove_From_Cart(MenuItem *item)
    {
        cart_items[item]--;
    }
    unordered_map<MenuItem *, int> Get_Cart_Items()
    {
        return cart_items;
    }
    float Get_Total()
    {
        float total = 0;
        for (auto i : cart_items)
        {
            total += i.first->get_price() * i.second;
        }
        return total;
    }
};
int Cart::nextId = 1;