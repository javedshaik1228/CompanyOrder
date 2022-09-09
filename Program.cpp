#include<iostream>
#include <vector>
#include <string>

#include "Customer.h"
#include "Order.h"
#include "Item.h"
#include "Company.h"

namespace CompanyApp{}
using namespace CompanyApp;

void addOrder(Customer &cus);
void placeOrders();
bool checkChoice(std::string objectType);

int main(){
    
    //add customers
    Company::enterCustomer();
    Company::enterCustomer();

    //add items
    Company::enterItem();
    Company::enterItem();

    std::cout<<"\nPlacing Orders"<<std::endl;
    placeOrders();

    //printing order values
    Company::displayTotalOrders();

    std::cout<<"\nEnter any key to exit"<<std::endl;
    std::string key = "";
    std::cin>>key;
        

    return 0;
}

void placeOrders(){
    long id;
    std::cout<<"Enter Customer ID: ";
    std::cin>>id;
    Customer *cus = Company::fetchCustomer(id);

    if(cus == nullptr){
        std::cout<<"Customer ID not valid!"<<endl;
        placeOrders();
        return;
    }

    //else
    addOrder(*cus);

    std::cout<<std::endl;

    if(checkChoice("Orders"))
        placeOrders();
    else
        return;


}

void addOrder(Customer &cus){
    
    Order *order = new Order();

        while(1){
            
            long itemCode;
            int quantity;
            std::cout<<"Enter Item Code: ";
            std::cin>>itemCode;
            std::cout<<"Enter Quantity: ";
            std::cin>>quantity;

            Item *item = Company::fetchItem(itemCode);
            if(item == nullptr){
                std::cout<<"Item Code is invalid! Please try again"<<std::endl;
                continue;
            }

            OrderItem *oItem = new OrderItem(item, quantity);
            order->addItems(oItem);

            if(checkChoice("Items"))
                continue;
            else
                break;

        }
    
    cus.addOrderToCus(order);
    std::cout<<"Added order Succesfully!"<<endl;
}

bool checkChoice(std::string objectType){
    std::cout<<"Add more " + objectType + "? y/n: ";
    char choice;
    std::cin>>choice;
    if(choice == 'y')
        return true;
    return false;
}
