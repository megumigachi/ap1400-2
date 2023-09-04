#include <iostream>
#include <gtest/gtest.h>
#include "ingredient.h"
#include "sub_ingredients.h"
#include "espresso_based.h"
#include "cappuccino.h"
#include "mocha.h"


class Test {
public:
    Test() {
        std::cout << "Test constructed" << std::endl;
    }
    ~Test() {
        std::cout << "Test destructed" << std::endl;
    }
};

std::vector<Test>* createVector() {
    return new std::vector<Test>(3);  // 创建包含3个 Test 对象的 vector，并返回其指针
}

void deleteVector(std::vector<Test>* vecPtr) {
    delete vecPtr;  // 删除 vector，触发其析构函数，从而触发所有 Test 对象的析构函数
}


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
    std::vector<Test>* vecPtr = createVector();  // 创建 vector，并获取其指针

    // 这里，你可以通过 vecPtr 使用 vector

    deleteVector(vecPtr);  
    std::cout<<vecPtr->size()<<std::endl;
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