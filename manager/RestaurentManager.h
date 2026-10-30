#include <bits/stdc++.h>
#include "../model/Restaurent.h"
using namespace std;

class RestaurantManager
{
    vector<Restaurant *> available_restaurent;
    static RestaurantManager *instance;
    RestaurantManager()
    {
        // private constructor
    }

public:
    static RestaurantManager *Create_Restarent_manager_Instance()
    {
        if (!instance)
            instance = new RestaurantManager();
        return instance;
    }

    vector<Restaurant *> Search_Restaurent_By_Location(string location)
    {
        vector<Restaurant *> nearest_restaurent;
        for (auto r : available_restaurent)
        {
            if (r->get_location() == location)
            {
                nearest_restaurent.push_back(r);
            }
        }
        return nearest_restaurent;
    }
    void Add_Restaurent(Restaurant *restaurent)
    {
        available_restaurent.push_back(restaurent);
    }
};

RestaurantManager *RestaurantManager::instance = nullptr;