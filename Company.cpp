#include <vector>
#include <iostream>
#include <string>

#include "Registered_Customer.h"
#include "Customer.h"
#include "Item.h"
#include "Company.h"

namespace CompanyApp{

    std::vector<Customer*> Company::_customers;
    std::vector<Item*> Company::_items;

    Company::Company(){

    }
    Company::~Company(){
      for(int i=0;i<_customers.size();i++){
        delete _customers[i];
      }
      for(int i=0;i<_items.size();i++){
        delete _items[i];
      }
    }

    void Company::enterCustomer()
    {
        std::string name;
        long id;
        std::cout<<"Enter name"<<std::endl;
        std::cin>>name;
        std::cout<<"Enter ID"<<std::endl;
        std::cin>>id;
        std::cout<<"Are they a registered customer? : y/n ";
        char choice;
        std::cin>>choice;
        
        Customer *cus;
        
        if(choice == 'y'){
            Reg_Customer *rcc = new Reg_Customer(name, id); 
            std::cout<<"Enter Discount percentage: "<<std::endl;
            double discount;
            std::cin>>discount;
            rcc->setSplDiscount(discount);
            cus = rcc; //upcasting
        }
        else{
            cus = new Customer(name,id);
        }
        _customers.push_back(cus);

    }

    void Company::enterItem()
    {
        long itemCode;
        std::string desc;
        double rate;
        
        std::cout<<"Enter ItemCode"<<std::endl;
        std::cin>>itemCode;
        
        std::cout<<"Enter description"<<std::endl;
        std::cin>>desc;
        
        std::cout<<"Enter rate"<<std::endl;
        std::cin>>rate;

        Item *item = new Item(itemCode, desc, rate);
        _items.push_back(item);

    }


    Item* Company::fetchItem(long itemCode){
        for(int i=0 ; i<_items.size(); i++){
            if(_items[i]->Item::getItemCode() == itemCode)
                return _items[i];
        }

        return nullptr;
    }

    Customer* Company::fetchCustomer(long id){
        for(int i=0 ; i<_customers.size(); i++){
            if(_customers[i]->Customer::getId() == id)
                return _customers[i];
        }

        return nullptr;
    }

    double Company::getTotalWorthOrders(){  
        double totalWorth = 0;
        for(int i=0 ; i<_customers.size(); i++){
            Reg_Customer *rcc= dynamic_cast<Reg_Customer *>(_customers[i]);
            if(rcc != NULL){
                totalWorth += rcc->getTotalValue();
            }
            else{
                totalWorth += _customers[i]->getTotalValue();
            }

        }

        return totalWorth;
    }

    void Company::displayTotalOrders(){
        for(int i=0 ; i<_customers.size(); i++){

            Reg_Customer *rcc= dynamic_cast<Reg_Customer *>(_customers[i]);
            if(rcc != NULL){
                std::cout<<"Total order for "<<rcc->getName()<<": "<<rcc->getTotalValue()<<std::endl;
            }
            else{
                std::cout<<"Total order for "<<_customers[i]->getName()<<": "<<_customers[i]->getTotalValue()<<std::endl;
            }
            
            
        }
        std::cout<<"The Total Order value is :"<<getTotalWorthOrders()<<std::endl;
    }

}