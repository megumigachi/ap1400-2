#include "espresso_based.h"

EspressoBased::EspressoBased() {
    // 空实现
}

EspressoBased::~EspressoBased() {
    // 空实现
}

std::vector<Ingredient*>& EspressoBased::get_ingredients(){
    return this->ingredients;
}