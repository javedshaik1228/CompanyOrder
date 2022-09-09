#pragma once
#include <string>
using namespace std;

namespace CompanyApp{
    class Item{
        private:
            long _itemCode;
            std::string _desc;
            double _rate;
        public:
            Item(long itemCode, std::string desc, double rate);

            double getRate();
            long getItemCode();
    };

}