#include <FoodFactory.hpp>

void FoodFactory::init() {
    sample.push_back("oniontomatobakeddough");
    sample.push_back("pepperonionionbakeddough");
    sample.push_back("sausagebakeddough");
    sample.push_back("pepperonibakeddough");
    sample.push_back("onionbakeddough");
    numFood = sample.size();
}

SampleFood* FoodFactory::get(Level* l, Customer* c) {
    int get_type = rand() % numFood;
    SampleFood* tmp = new SampleFood(sample[get_type]);
    return tmp;
}