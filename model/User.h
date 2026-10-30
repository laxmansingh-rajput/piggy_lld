#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
#include "./Cart.h"
using namespace std;

class User
{
    static int next_id;
    int id;
    string name;
    string location;
    int contact;
    Cart *cart;

public:
    User(string name, string location, int contact)
    {
        this->name = name;
        this->location = location;
        this->contact = contact;
        cart = new Cart();
        id = next_id++;
    }
    // Getters
    int getId() const
    {
        return id;
    }

    string getlocation() const
    {
        return location;
    }

    int getcontact() const
    {
        return contact;
    }

    Cart *getCart() const
    {
        return cart;
    }

    void setlocation(const string &location)
    {
        this->location = location;
    }
    string getName() const
    {
        return name;
    }
    void setcontact(int contact)
    {
        contact = contact;
    }

    void setCart(Cart *cart)
    {
        this->cart = cart;
    }
};
int User::next_id = 1;
#endif // USER_H
