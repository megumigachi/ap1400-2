#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>

class Ingredient
{
public:
    double get_price_unit()
    {
        return this->price_unit;
    };
    size_t get_units()
    {
        return this->units;
    };
    virtual std::string get_name() = 0;
    virtual Ingredient *clone() = 0;

    double price()
    {
        return this->price_unit * this->units;
    };

protected:
    Ingredient(double price_unit, size_t units)
    {
        this->price_unit = price_unit;
        this->units = units;
    };

    double price_unit;
    size_t units;
    std::string name;
};

// double Ingredient::price(){
//     return 0.0;
// }
#endif // INGREDIENT_H