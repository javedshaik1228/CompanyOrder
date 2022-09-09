#include <vector>
#include <utility>

#include "OrderItem.h"
#include "Order.h"

namespace CompanyApp{

    void Order::addItems(OrderItem *oItem){
        _orderedItems.push_back(oItem);
        _orderTotal += oItem->getTotal();;
    }

    double Order::getOrderTotal(){
        return _orderTotal;
    }

}