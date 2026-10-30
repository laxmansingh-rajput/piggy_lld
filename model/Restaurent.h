
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <bits/stdc++.h>
#include "./Menu.h"

    using namespace std;

class Restaurant
{
private:
    int restaurant_id;
    static int Next_Id;
    string restaurant_name;
    string location;
    Menu *menu;

public:
    // Constructor
    Restaurant(const string &Restaurant_Name, const string &Location)
        : restaurant_id(Next_Id++),
          restaurant_name(Restaurant_Name),
          location(Location),
          menu(new Menu())
    {
    }

    // Getters
    int get_restaurant_id() const
    {
        return restaurant_id;
    }

    string get_restaurant_name() const
    {
        return restaurant_name;
    }

    string get_location() const
    {
        return location;
    }

    // Setters
    void set_restaurant_name(const string &name)
    {
        restaurant_name = name;
    }

    void set_location(const string &location)
    {
        this->location = location;
    }

    // Menu operations
    void Add_Item(int name, float price)
    {
        menu->Add_Item(name, price, restaurant_id);
    }

    void Remove_Item(int id)
    {
        menu->Remove_Item(id);
    }

    // Destructor
    ~Restaurant()
    {
        delete menu;
    }
};

int Restaurant::Next_Id = 1;

#endif
