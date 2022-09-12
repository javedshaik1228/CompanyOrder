#include <vector>
#include <utility>

#include "OrderItem.h"
#include "Order.h"

namespace CompanyApp{

    Order::Order(){

    }
    Order::~Order(){
        for(int i=0;i<_orderedItems.size();i++){
            delete _orderedItems[i];
        }
    }

    void Order::addItems(OrderItem *oItem){
        _orderedItems.push_back(oItem);
        _orderTotal += oItem->getTotal();;
    }

    double Order::getOrderTotal(){
        return _orderTotal;
    }

}