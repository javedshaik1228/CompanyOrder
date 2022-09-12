#include <string>
#include <vector>

#include "Order.h"
#include "Customer.h"

namespace CompanyApp{

        Customer::Customer(std::string name, long id){
            _name = name;
            _id = id;
        }

        long Customer::getId(){
            return _id;
        }

        std::string Customer::getName(){
            return _name;
        }

        void Customer::addOrderToCus(Order* order){
            _orders.push_back(order);
            Customer::totalValue += order->getOrderTotal();

        }
        double Customer::getTotalValue(){
            return totalValue;
        }
        Customer::~Customer(){
            for(int i=0;i<_orders.size();i++){
                delete _orders[i];
            }
        }
        

}