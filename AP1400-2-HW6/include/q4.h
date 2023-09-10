#ifndef Q4_H
#define Q4_H
#include <vector>
namespace q4
{
    struct Vector2D
    {
        double x{};
        double y{};

        Vector2D(double x_value, double y_value) : x(x_value), y(y_value){};
    };

    struct Sensor
    {
        Vector2D pos;
        double accuracy;
    };

    double get_base(std::vector<Sensor> sensors)
    {
        double res{};
        for (auto x : sensors)
        {
            res += x.accuracy;
        }
        return res;
    }

    double get_x(std::vector<Sensor> sensors)
    {
        double x{};
        for (auto s : sensors)
        {
            x += s.pos.x * s.accuracy / get_base(sensors);
        }
        return x;
    }

    double get_y(std::vector<Sensor> sensors)
    {
        double y{};
        for (auto s : sensors)
        {
            y += s.pos.y * s.accuracy / get_base(sensors);
        }
        return y;
    }

    Vector2D kalman_filter(std::vector<Sensor> sensors)
    {
        return Vector2D{get_x(sensors), get_y(sensors)};
    }
}

#endif // Q4_H