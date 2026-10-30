#include <bits/stdc++.h>
#include "./manager/RestaurentManager.h"
#include "./manager/OrderManager.h"
#include "./services/OrderService.h"
#include "./model/Restaurent.h"
#include "./model/User.h"
#include "./model/Order.h"

using namespace std;

class Piggy
{
    RestaurantManager *restarant_manager;
    OrderManager *order_manager;
    OrderService *order_service;

public:
    Piggy()
    {
        restarant_manager = RestaurantManager::Create_Restarent_manager_Instance();
        order_manager = OrderManager::create_order_manager();
        order_service = new OrderService();
        Restaurant *restaurant1 = new Restaurant("Bikaner", "Delhi");
        restaurant1->Add_Item("Chole Bhature", 120);
        restaurant1->Add_Item("Samosa", 15);

        Restaurant *restaurant2 = new Restaurant("Haldiram", "Kolkata");
        restaurant2->Add_Item("Raj Kachori", 80);
        restaurant2->Add_Item("Pav Bhaji", 100);
        restaurant2->Add_Item("Dhokla", 50);

        Restaurant *restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");
        restaurant3->Add_Item("Masala Dosa", 90);
        restaurant3->Add_Item("Idli Vada", 60);
        restaurant3->Add_Item("Filter Coffee", 30);

        restarant_manager->Add_Restaurent(restaurant1);
        restarant_manager->Add_Restaurent(restaurant2);
        restarant_manager->Add_Restaurent(restaurant3);
    }

    vector<Restaurant *> Search_Restaurent_By_Location(string location)
    {
        return restarant_manager->Search_Restaurent_By_Location(location);
    }

    void Add_To_Cart(User *user, MenuItem *item)
    {
        (user->getCart())->Add_To_Cart(item);
    }

    void Create_Order_Of_Cart(User *user, string order_type, string payment_type)
    {
        auto items = user->getCart()->Get_Cart_Items();
        float amount = user->getCart()->Get_Total();
        Order *order = order_service->createOrder(order_type, amount, payment_type, items);
        order_manager->Add_User_Order(user, order);
    }

    void Pay_For_Order(User *user, Order *order, string payment_type, int id, int password)
    {
        if (order->get_payment()->get_status())
        {
            cout << "Order is Already Payed" << endl;
            return;
        }
        if (payment_type != order->get_payment()->Get_Payment_Type())
        {
            order->get_payment()->Change_strategy(payment_type);
        }
        order->get_payment()->Pay(id, password);
        order->Initiate_Order_Lifecycle();
    }
    vector<Order *> Get_Order(User *user)
    {
        return order_manager->get_user_orders(user);
    }
};