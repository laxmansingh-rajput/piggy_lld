#include <bits/stdc++.h>
#include "./MenuItem.h"
#include "./Restaurent.h"

using namespace std;

class Menu
{
public:
    vector<MenuItem *> RestaurentMenu;
    void Get_Items()
    {
        return RestaurentMenue;
    }
    void Add_Item(int name, float price, int restaurant_id)
    {
        int item_id = RestaurentMenu.size() + 1;
        MenuItem *item = new MenuItem(item_id, name, price, restaurant_id);
        RestaurentMenu.push_back(m);
    }
    void Remove_Item(int id)
    {
        MenuItem *item = nullptr;
        for (auto i : RestaurentMenu)
        {
            if (i->item_id == item_id)
            {
                item = i;
            }
        }
        if (item != nullptr)
            RestaurentMenu.erase(item);
    }
};
