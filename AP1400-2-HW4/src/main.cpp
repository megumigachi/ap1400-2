#include <iostream>
#include <gtest/gtest.h>
#include "unique_ptr.h"
#include "shared_ptr.h"

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        SharedPtr<double> ptr1{new double{1.567}};
        SharedPtr<double> ptr2{new double{5.1234}};
        ptr1 = ptr1;
        ptr2 = SharedPtr<double>(ptr1);
        EXPECT_DOUBLE_EQ(*ptr2, 1.567);
        EXPECT_EQ(ptr1.use_count(), 2);
        EXPECT_EQ(ptr2.use_count(), 2);
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