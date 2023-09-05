#include <iostream>
#include <thread>
#include <chrono>
#include <gtest/gtest.h>
#include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"
#include "cappuccino.h"
#include "mocha.h"

class MyClass
{
public:
    std::vector<int> myVector;

    MyClass()
    {
        myVector.push_back(1);
    }

    ~MyClass()
    {
        std::cout << "~Myclass()" << std::endl;
    }
};

class MyClass2 : public MyClass
{
public:
    std::vector<int> myVector2;

    MyClass2()
    {
        myVector2.push_back(2);
    }
    ~MyClass2()
    {
        std::cout << "~Myclass2()" << std::endl;
    }
};

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        MyClass2 *esp{new MyClass2{}};
        auto &sides = esp->myVector;
        auto &sides2 = esp->myVector2;
        delete esp;
        EXPECT_EQ(sides2.size(), 1);
        EXPECT_EQ(sides.size(), 1);
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}