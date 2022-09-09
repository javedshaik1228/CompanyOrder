#include <string>

#include "Item.h"
namespace CompanyApp{
            
    Item::Item(long itemCode, std::string desc, double rate){
        _itemCode = itemCode;
        _desc = desc;
        _rate = rate;
    }

    double Item::getRate(){
        return _rate;
    }
    
    long Item::getItemCode(){
        return _itemCode;
    }

}