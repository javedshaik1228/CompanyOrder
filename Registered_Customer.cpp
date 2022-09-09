#include <string>
#include "Customer.h"
#include "Registered_Customer.h"

namespace CompanyApp {

    Reg_Customer::Reg_Customer(std::string name, long id) : Customer(name, id){
	}

	void Reg_Customer::setSplDiscount(double discount) {
		_splDiscount = discount/100;
	}

	double Reg_Customer::getTotalValue() {
		return totalValue - (_splDiscount * totalValue);
	}
}