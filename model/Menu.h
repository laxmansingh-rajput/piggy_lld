#ifndef MENU_H
#define MENU_H
#include <bits/stdc++.h>
#include "./MenuItem.h"
#include "./Restaurent.h"

using namespace std;

class Menu
{
public:
    vector<MenuItem *> RestaurentMenu;
    vector<MenuItem *> Get_Items()
    {
        return RestaurentMenu;
    }
    void Add_Item(string name, float price, int restaurant_id)
    {
        int item_id = RestaurentMenu.size() + 1;
        MenuItem *item = new MenuItem(item_id, name, price, restaurant_id);
        RestaurentMenu.push_back(item);
    }
    void Remove_Item(int item_id)
    {
        MenuItem *item = nullptr;
        for (auto i : RestaurentMenu)
        {
            if (i->get_item_id() == item_id)
            {
                item = i;
            }
        }
        if (item != nullptr)
        {
            auto it = find(RestaurentMenu.begin(), RestaurentMenu.end(), item);
            RestaurentMenu.erase(it);
        }
    }
};
#endif