#include <FoodFactory.hpp>

void FoodFactory::init() {
    sample.push_back("dough");
    sample.push_back("doughdough");
    numFood = sample.size();
}

SampleFood* FoodFactory::get(Level* l, Customer* c) {
    int get_type = rand() % numFood;
    SampleFood* tmp = new SampleFood(sample[get_type]);
    return tmp;
}