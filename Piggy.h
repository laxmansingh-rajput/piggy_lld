#include <bits/stdc++.h>
#include "./manager/RestaurentManager.h"
#include "./model/Restaurent.h"
#include "./model/User.h"
using namespace std;

class Piggy
{
    RestaurantManager *restarant_manager;

public:
    Piggy()
    {
        restarant_manager = RestaurantManager::Create_Restarent_manager_Instance();

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
    void Create_Order_Of_Cart(User *user)
    {
    }
};