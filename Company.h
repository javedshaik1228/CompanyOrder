#pragma once

namespace CompanyApp{

    class Company{

        static std::vector<Customer*> _customers;
        static std::vector<Item*> _items;
        static double getTotalWorthOrders();

        public:
            double getWorthOfOrdersPlaced();
            static void enterCustomer();
            static void enterItem();
            
            // Fun to fecth an Item Pointer object based on itemCode
            static Item* fetchItem(long itemCode);

            // Fun to fecth a customer Pointer object based on id
            static Customer* fetchCustomer(long id);

            // Fun to get total worth of orders placed


            // Fun to print total worth of orders per customer
            static void displayTotalOrders();
    };

}