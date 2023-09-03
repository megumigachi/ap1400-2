#ifndef SUB_INGREDIENTS_H
#define SUB_INGREDIENTS_H

#include"ingredient.h"

#define DEFCLASS(className, cost)  \
class className:public Ingredient \
{ \
public: \
    className(size_t units) : Ingredient{cost, units} \
    { \
        this->name = #className; \
    } \
    std::string get_name() override{return this->name;} \
};

// 使用宏来定义类
 DEFCLASS(Cinnamon, 5);
 DEFCLASS(Chocolate, 5);
 DEFCLASS(Sugar, 1);
 DEFCLASS(Cookie, 10);
 DEFCLASS(Espresso, 15);
 DEFCLASS(Milk, 10);
 DEFCLASS(MilkFoam, 5);
 DEFCLASS(Water, 1);


#endif // SUB_INGREDIENTS_H