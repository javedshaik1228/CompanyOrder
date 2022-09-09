#pragma once
#include "OrderItem.h"

namespace CompanyApp{

    class Order{
        
        std::vector<OrderItem*> _orderedItems;     //vector of pairs, pair.first = item, pair.second  = quantity
        double _orderTotal;
        public:
            void addItems( OrderItem *_oItem );   
            double getOrderTotal();
    };

}