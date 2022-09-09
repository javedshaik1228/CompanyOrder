#pragma once
#include <string>
#include "Customer.h"

namespace CompanyApp{

    class Reg_Customer : public Customer{
        private:
            double _splDiscount;
        public:

        Reg_Customer(std::string name, long id);
        void setSplDiscount(double discount);
        double getTotalValue();
    };

}