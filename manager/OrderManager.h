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
    unordered_map<Restaruret *, vector<Order *>> restarurent_orders;

    OrderManager()
    {
        // private constructor
    }

public:
    OrderManager *create_order_manager()
    {
        if (!order_manager_instance)
        {
            order_manager_instance = new OrderManager();
        }
        return order_manager_instance;
    }
    void get_user_order(User *user)
    {
        return user_order[user];
    }
    void get_user_order(Restaurent *restarurent)
    {
        return restarurent_order[restarurent];
    }
};

OrderManager *OrderManager::order_manager_instance = nullptr;
