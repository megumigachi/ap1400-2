#include "cappuccino.h"
#include "sub_ingredients.h"

Cappuccino::Cappuccino()
{
    this->ingredients = std::vector<Ingredient *>{};
    (this->ingredients).push_back(new Espresso{2});
    (this->ingredients).push_back(new Milk{2});
    (this->ingredients).push_back(new MilkFoam{1});
    this->side_items = std::vector<Ingredient *>{};
}

Cappuccino::Cappuccino(const Cappuccino &other)
{
    this->ingredients = std::vector<Ingredient *>{};
    for (auto &&i : other.ingredients)
    {
        this->ingredients.push_back(i->clone());
    }
    this->side_items = std::vector<Ingredient *>();
    for (auto &&i : other.side_items)
    {
        this->ingredients.push_back(i->clone());
    }
}

std::string Cappuccino::get_name()
{
    return "Cappuccino";
}

double Cappuccino::price()
{
    double sum = 0;
    for (auto &&i : this->ingredients)
    {
        sum += i->price();
    }
    for (auto &&i : this->side_items)
    {
        sum += i->price();
    }

    return sum;
}

Cappuccino::~Cappuccino()
{
    for (auto &&i : this->ingredients)
    {
        delete i;
    }
    ingredients.clear();
    for (auto &&i : this->side_items)
    {
        delete i;
    }
    side_items.clear();
}

void Cappuccino::add_side_item(Ingredient *ingredient)
{
    this->side_items.push_back(ingredient);
}

std::vector<Ingredient *> &Cappuccino::get_side_items()
{
    return this->side_items;
}

void Cappuccino::operator=(const Cappuccino &other)
{
    if (this == &other)
    {
        return;
    }

    this->ingredients.clear();
    for (auto &&i : other.ingredients)
    {
        this->ingredients.push_back(i->clone());
    }
    this->side_items.clear();
    for (auto &&i : other.side_items)
    {
        this->ingredients.push_back(i->clone());
    }
}