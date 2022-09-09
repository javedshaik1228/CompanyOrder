#pragma once
#include <vector>
#include "Order.h"

namespace CompanyApp{
    class Customer{
        protected:
            std::string _name;
            long _id;
            std::vector<Order*> _orders;
            double totalValue = 0;
        public:
            Customer(std::string name, long id);
            long getId();
            std::string getName();
            void addOrderToCus(Order* order);
            double getTotalValue();
            virtual ~Customer();

    };

}