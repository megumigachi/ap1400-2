#ifndef Q1_H
#define Q1_H
#include <iostream>
#include <functional>

namespace q1
{

    // 非泛型版本，用于前两个测试用例
    double gradient_descent(double initial_point, double learning_rate, std::function<double(double)> func)
    {
        double x = initial_point;
        double step = 0.00001;
        double gradient = (func(x + step) - func(x - step)) / (2 * step);
        while (abs(gradient) > 0.0001)
        {
            x -= learning_rate * gradient;
            gradient = (func(x + step) - func(x - step)) / (2 * step);
        }
        return x;
    };

    //  泛型版本，主要用于第三个测试用例
    template <typename ReturnType = double, typename FuncType>
    ReturnType gradient_descent(ReturnType initial_point, ReturnType learning_rate)
    {
        //     std::cout << "calling this" << std::endl;
        FuncType func = FuncType();
        // 转换为std::function
        std::function<ReturnType(ReturnType)> stdFunc = func;

        // 委托给非模板版本
        ReturnType result = static_cast<ReturnType>(
            gradient_descent(static_cast<double>(initial_point), static_cast<double>(learning_rate), stdFunc));

        return result;
    }

    // template <typename T, typename F>
    // T gradient_descent(T init, T step)
    // {
    //     return gradient_descent(init, step, F());
    // }

} // namespace q1

#endif // Q1_H