#include <CustomerFactory.hpp>

CustomerFactory* CustomerFactory::cf = new CustomerFactory();

void CustomerFactory::init() {
    ff = new FoodFactory();
}

Customer* CustomerFactory::get(Level* l, Customer* c) {
    Customer* customer = c;
    int type = rand() % 2;
    switch (l -> level) 
    {
    case 1:
        customer -> status = new YoungCustomerState(customer);
        break;
    case 2:
        switch (type) {
            case 0:
                customer -> status = new YoungCustomerState(customer);
                break;
            case 1:
                customer -> status = new OldCustomerState(customer);
                break;
            default:
                customer -> status = new YoungCustomerState(customer);
                break;
        }
        break;
    case 3:
        customer -> status = new SpecialCustomerState(customer);
        break;
    default:
        customer -> status = new OldCustomerState(customer);
        break;
    }
    customer -> setSampleFood(ff -> get(l, c));
    return nullptr;
}