#include <string>
using namespace std;
#include "OrderItem.h"
#include "Item.h"

namespace CompanyApp{
    OrderItem::OrderItem(Item *item, int qty) : item(item), qty(qty)
    {
    }

    OrderItem::~OrderItem()
    {
    }

    Item *OrderItem::getItem() const
    {
        return item;
    }
    int OrderItem::getQuantity() const
    {
        return qty;
    }
    double OrderItem::getTotal() const
    {
        return item->getRate() * qty;
    }
}