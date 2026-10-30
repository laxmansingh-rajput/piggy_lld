#include <bits/stdc++.h>
#include "./Piggy.h"
#include "./model/User.h"
#include "./model/Restaurent.h"
using namespace std;
int main()
{
    // Create TomatoApp Object
    Piggy *pig = new Piggy();

    // Simulate a user coming in (Happy Flow)
    User *user = new User("Laxman", "Indore", 992662102);
    cout << "User: " << user->getName() << " is active." << endl;

    // User searches for restaurants by location
    vector<Restaurant *> available_restaurent = pig->Search_Restaurent_By_Location("Delhi");
    if (available_restaurent.size() == 0)
    {
        cout << "No  Restaruent available currently" << endl;
        return 0;
    }
    else
    {
        for (auto r : available_restaurent)
        {
            cout << r->get_restaurant_name() << endl;
        }
    }
    pig->Add_To_Cart(user, available_restaurent[0]->get_menu()->Get_Items()[0]);
    pig->Add_To_Cart(user, available_restaurent[0]->get_menu()->Get_Items()[0]);
    pig->Add_To_Cart(user, available_restaurent[0]->get_menu()->Get_Items()[0]);
    pig->Add_To_Cart(user, available_restaurent[0]->get_menu()->Get_Items()[1]);
    pig->Add_To_Cart(user, available_restaurent[0]->get_menu()->Get_Items()[1]);

    auto user_cart = user->getCart()->Get_Cart_Items();
    cout << user->getName() << " with userId: " << user->getId() << " cart:" << endl;
    for (auto &entry : user_cart)
    {
        MenuItem *item = entry.first;
        int quantity = entry.second;
        cout << item->get_ItemName() << " " << quantity << " " << item->get_price() << endl;
    }
    cout << "Toal Amount " << user->getCart()->Get_Total() << endl;

    return 0;
}