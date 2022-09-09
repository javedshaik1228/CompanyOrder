#pragma once

namespace CompanyApp{
    class Item;
    class OrderItem
    {
        private:
            Item *item;
            int qty;
        public:
            OrderItem(Item *item, int qty);
            ~OrderItem();

            Item *getItem() const;
            int getQuantity() const;
            double getTotal() const;
    };

}