#ifndef OrderManager_H
#define OrderManager_H
#include <bits/stdc++.h>
#include "../model/Order.h"
#include "../model/Restaurent.h"
#include "../model/User.h"

using namespace std;
class OrderManager
{
    static OrderManager *order_manager_instance;
    vector<Order *> orders;
    unordered_map<User *, vector<Order *>> user_orders;
    unordered_map<Restaurant *, vector<Order *>> restaurent_orders;

    OrderManager()
    {
        // private constructor
    }

public:
    static OrderManager *create_order_manager()
    {
        if (!order_manager_instance)
        {
            order_manager_instance = new OrderManager();
        }
        return order_manager_instance;
    }

    void Add_User_Order(User *user, Order *order)
    {
        user_orders[user].push_back(order);
    }

    void Add_User_Restaurant(Restaurant *restaurent, Order *order)
    {
        restaurent_orders[restaurent].push_back(order);
    }

    vector<Order *> get_user_orders(User *user)
    {
        return user_orders[user];
    }

    vector<Order *> get_restaurant_orders(Restaurant *restaurant)
    {
        return restaurent_orders[restaurant];
    }
};

OrderManager *OrderManager::order_manager_instance = nullptr;
#endif