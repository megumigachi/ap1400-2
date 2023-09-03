#include "cappuccino.h"
#include "sub_ingredients.h"

Cappuccino::Cappuccino() {
    this->ingredients = std::vector<Ingredient*>{};
    (this->ingredients).push_back(new Espresso{2});
    (this->ingredients).push_back(new Milk{2});
    (this->ingredients).push_back(new MilkFoam{1});
    this->side_items = std::vector<Ingredient*>{};
}

std::string Cappuccino::get_name(){
    return "Cappuccino";
}

double Cappuccino::price(){
    return 0.0;
}

Cappuccino::~Cappuccino(){
    
}